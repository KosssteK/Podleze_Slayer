#include "naboje.h"




///======================PROST=
prosta::prosta()
{
	a = 1;
	b = 1;
}

prosta::prosta(double a, double b)
{
	this->a = a;
	this->b = b;
}
prosta rownanie(double x, double y, double a, double b)
{

	//y = a*x + b;	(3,1)	1=3a+b	b=1-3a				b=-2
	//y = a*x + b;	(5,3)	3=5a+b	3=5a+1-3a	2=2a	a=1
	//	y1-y2=ax1-ax2	y1-y2=a(x1-x2)	a=(y1-y2)/(x1-x2)
	//b = y1 - ax1;

	prosta Wynik;
	if ((x - a) != 0)
	{
		Wynik.a = (y - b) / (x - a);
		//	Wynik.b = y - (Wynik.a * x);
		Wynik.b = 0;
	}
	else
	{
		Wynik.a = 0;
		Wynik.b = 0;
	}
	return Wynik;
}
punkt wspPkt(prosta A)
{
	// a b x1 y1 x2 y2

	double a1, b1, c1;
	int r = 40;
	double delta;
	double x1, x2;
	double y1, y2;
	int X, Y;
	//x ^ 2 + y ^ 2 = r ^ 2												x ^ 2 + y ^ 2 = r^2		x^2 + (ax+b)^2 =r^2		xx + aaxx +2abx +bb = rr		1-aa(xx) +2abx +bb-rr =0	d=16 + 4*21*2	184
	//y = a*x + b																									y=x-2
	//prosta X(1,0);
	//wspPkt(X, 1);

	//std::cout << A.a << "   1   " << A.b << std::endl;

	a1 = 1 + (A.a*A.a);
	//a1 = 1 + A.a;
	b1 = 2 * A.a * A.b;
	c1 = (A.b*A.b) - r*r;

	delta = (b1*b1) - (4 * a1*c1);

	x1 = (-1 * b1 + sqrt(delta)) / (2 * a1);
	x2 = (-1 * b1 - sqrt(delta)) / (2 * a1);

	//std::cout << x1 << "   2   " << x2 << std::endl;
	y1 = A.a*x1 + A.b;
	y2 = A.a*x2 + A.b;

	//std::cout << y1 << "   3   " << y2 << std::endl;
	X = x1;
	Y = y1;
	//std::cout << X << "   4   " << Y << std::endl;
	punkt G(X, Y);
	return G;

}
void stosunek(naboj *Head, double &x, double &y, double X, double Y, int cw)
{
	int v = 1;
	
	if (cw == 1)
	{
		x = x + v * X;
		y = y + v * Y;
		//std::cout << "1" << std::endl;
	}
	else if (cw == 2)

	{
		//std::cout << "2" << std::endl;
		x = x - v * X;
		y = y - v * Y;
	}
	else if (cw == 3)

	{
		//std::cout << "3" << std::endl;
		x = x - v * X;
		y = y - v * Y;
	}
	else if (cw == 4)

	{
		//std::cout << "4" << std::endl;
		x = x + v * X;
		y = y + v * Y;
	}


}

//==========================NABOJ
naboj::naboj()
{
	x = 0;
	y = 0;
}
naboj::naboj(double x, double y, double a, double b,float kat)
{
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
	this->kat = kat;
 
	prosta A = rownanie(x, y, a, b);
	punkt XY = wspPkt(A);
	double a1 = XY.x * 10000;
	double a2 = XY.y * 10000;
	int b1 = a1;
	int b2 = a2;
	a1 = b1 / 10000;
	a2 = b2 / 10000;




	this->stos1 = a1;
	this->stos2 = a2;


	//double przec = 0;
	//double m = (a-x);
	//double n = (b-y);
	//double wartosc = 0;
	//double wartosc2 = 0;
	//przec = sqrt(m*m + n*n);

	////x += 5;
	//if ((x - a) != 0 && (y - b) != 0)
	//{
	//	wartosc = (b - y) / przec;
	//}
	//else
	//{
	//	if ((x - a) == 0)
	//	{
	//		wartosc = 1;
	//	}
	//	else
	//	{
	//		if ((y - b) == 0)
	//		{
	//			wartosc = 0;
	//		}
	//	}

	//}
	////	wartosc = wartosc * 100;
	//if (wartosc < 0)
	//{
	//	wartosc = -wartosc;
	//}


	//wartosc2 = 1 - wartosc;
	//double Ax = 1, Ay = 1;
	//double stos1 = 1, stos2 = 1;
	//stos2 = stos2*wartosc;
	//stos1 = stos1*wartosc2;


	/*this->stos1 = stos1;
	this->stos2 = stos2;*/
	//if ((x - a) != 0 && (y - b) != 0)
	//{
	//	this->stos1 = m/n;
	//	this->stos2 = n/m;
	//}


	//this->stos1 = stos1;
	//this->stos2 = stos2;
	//std::cout << x << " " << y << " " << a << " " << b << std::endl;
			if (a>x && b<y)
			{
				//std::cout << "1" << std::endl;
				this->cw = 1;
			}
			else if (a<x && b<y)
			{
			//	std::cout << "2" << std::endl;
				this->cw = 2;
			}
			else if (a>x && b>y)
			{
			//	std::cout << "4" << std::endl;
				this->cw = 4;
			}
			else if (a<x && b>y)
			{
			//	std::cout << "3" << std::endl;
				this->cw = 3;
			}




}
double naboj::poruszaj(naboj *Head, double &x, double &y, double stos1, double stos2, int cw, float kat)
{
	if (Head != NULL)
	{
		
	//	double przec = 0;
	//	double m = (x - a);
	//	double n = (y - b);
	//	double wartosc = 0;
	//	double wartosc2 = 0;
	//	przec = sqrt(m*m + n*n);

	//	//x += 5;
	//	if ((x - a) != 0 && (y - b) != 0)
	//	{
	//		wartosc= (b-y) / przec;
	//	}
	//	else
	//	{
	//		if ((x - a) == 0)
	//		{
	//			wartosc =  1;
	//		}
	//		else
	//		{
	//			if ((y - b) == 0)
	//			{
	//				wartosc= 0;
	//			}
	//		}

	//	}
	////	wartosc = wartosc * 100;
	//	if (wartosc < 0)
	//	{
	//		wartosc = -wartosc;
	//	}


	//	wartosc2 = 1-wartosc;
	//	double Ax = 1, Ay = 1;
	//	double stos1 = 1, stos2 = 1;
	//	stos2 = stos2*wartosc;
	//	stos1 = stos1*wartosc2;
	//	//double stos=kat/1.57-1;
	//	//std::cout << kat << "   " << stos << std::endl;
	//	while(stos1<0 || stos2<0)
	//	{
	//		stos1++;
	//		stos2++;
	//	}

	//	///tutaj ify na cwiartki
		int v = 1;
		if (cw==1)
		{
			x = x + v * (stos1 + 1);
			y = y - v * (stos2 + 1);
			//std::cout << "1" << std::endl;
		}
		else if (cw==2)
		
		{
			//std::cout << "2" << std::endl;
			x = x - v * (stos1 + 1);
			y = y - v * (stos2 + 1);
		}
		else if (cw==3)

		{
			//std::cout << "3" << std::endl;
			x = x - v * (stos1+1);
			y = y + v * (stos2 + 1);
		}
		else if (cw==4)

		{
			//std::cout << "4" << std::endl;
			x = x + v * (stos1 + 1);
			y = y + v * (stos2 + 1);
		}
	

		//return 0;


	}
	return 0;
}
void naboj::dorzuc(naboj *&Head, double x, double y, double a, double b, float kat)
{
	naboj*p = new naboj(x,y,a,b,kat);
	naboj*p1 = Head;
	naboj *p2 = Head;
	if (Head == NULL)
	{
		p->next = NULL;
		Head = p;
		//std::cout << "1" << std::endl;
	}
	else
	{
		while (p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
			//std::cout << "2" << std::endl;
		}
		p->next = p1->next;
		p1->next = p;
		//std::cout << "3" << std::endl;

	}

	
}
void naboj::wyswietl(naboj *Head)
{
	naboj *p = Head;
	std::cout << "Head" << "->";
	if (Head != NULL)
	{

		while (p != NULL)
		{
			std::cout << p->x << "|" << p->y << "|"<< p->a <<"|" <<p->b << "|" << p->kat << "->";
			p = p->next;
		}
	}
	std::cout << "NULL" << std::endl;
}
bool naboj::wyrzuc(naboj *&Head, naboj *&wsk)
{
	naboj *p = Head;
	naboj *p1 = p;
	naboj* p2 = p;
	if (Head != NULL)
	{
		if (p == Head)
		{
			if (p->x < 0 || p->y < 0 || p->x > 800 || p->y > 600)
			{
				Head = Head->next;
				//std::cout << "========" << Head << std::endl;
				delete p;
				wsk = Head;
				return 1;
				//p = Head;
			}
			//p = p->next;
		}
		else
		{

			while (p->next != NULL)
			{

				if (p->x < 0 || p->y < 0 || p->x > 800 || p->y > 600)
				{

					p1->next = p->next;

					delete p;
					wsk = Head;
					return 1;
				}
				p1 = p;
				p = p->next;
			}

		}


	}
	return 0;
	//wsk = Head;
	/*else
	{
		if (Head->next == NULL)
		{
			if (Head->x == 0 || Head->y == 0)
			{
				Head = Head->next;
				delete p;
			}
		}
	}*/

}



//================PUNKT
punkt::punkt()
{
	this->x = 0;
	this->y = 0;
}
punkt::punkt(double x, double y)
{
	this->x = x;
	this->y = y;
}



template <class Klasa>
void wyswietl(Klasa *Head)
{
	Klasa *p = Head;
	std::cout << "Head" << "->";
	if (Head != NULL)
	{

		while (p != NULL)
		{
		//	std::cout << p->x << "|" << p->y  << "->";
			cout << "asd" << endl;
			p = p->next;
		}
	}
	std::cout << "NULL" << std::endl;
}