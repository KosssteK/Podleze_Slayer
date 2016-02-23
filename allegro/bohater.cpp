#include "bohater.h"

bohater::bohater(int _x, int _y, int _zycie)
{
	x = _x;
	y = _y;
	zycie = _zycie;
	this->punkty = 0;
	//sprite = _sprite;
	//nazwa = _nazwa;
}
void bohater::reset()
{
	this->x = 400;
	this->y = 300;
	this->punkty = 0;
	this->zycie = 100;
}
void bohater::wypisz()
{
	std::cout << x << "  " << y << std::endl;

}
//==============POTWOR
potwor::potwor()
{
	int a;
	a = rand() % 4;
	if (a == 0)
	{
		this->x = 2;
		this->y = rand() % 598 + 1;
	}
	else if (a == 1)
	{
		this->x = 798;
		this->y = rand() % 598 + 1;
	}
	else if (a == 2)
	{
		this->x = rand() % 798 + 1;
		this->y = 2;
	}
	else if (a == 3)
	{
		this->x = rand() % 798 + 1;
		this->y = 598;
	}
	//std::cout << "nowy potwor" << std::endl;
}
void potwor::wypisz()
{
	std::cout  << "ID: " << this->ID << "    X: "<< x <<"     Y: " << y << std::endl;

}




void potworRuch(double &x, double &y, double X, double Y)
{
	//std::cout << "asd" << std::endl;
	double v = 0.01;
	int cw = 0;
	prosta A = rownanie(x, y, X, Y);
	punkt XY = wspPkt(A);


	if (X>x && Y<y)
	{
		//std::cout << "1" << std::endl;
		cw = 1;
	}
	else if (X<x &&Y<y)
	{
			//std::cout << "2" << std::endl;
		cw=2;
	}
	else if (X>x && Y>y)
	{
		//	std::cout << "4" << std::endl;
		cw = 4;
	}
	else if (X<x && Y>y)
	{
			//std::cout << "3" << std::endl;
		cw = 3;
	}





	if (cw == 1)
	{
		x = x + v * XY.x;
		y = y + v * XY.y;
		//std::cout << "1*" << std::endl;
	}
	else if (cw == 2)

	{
		//std::cout << "2*" << std::endl;
		x = x - v * XY.x;
		y = y - v * XY.y;
	}
	else if (cw == 3)

	{
		//std::cout << "3*" << std::endl;
		x = x - v * XY.x;
		y = y - v * XY.y;
	}
	else if (cw == 4)

	{
		//std::cout << "4*" << std::endl;
		x = x + v * XY.x;
		y = y + v * XY.y;
	}

	
}
void potwor::dorzuc(potwor *&Head, int &liczba, int &licznik)
{
	potwor*p = new potwor();
	noweID(p,licznik);
	potwor*p1 = Head;
	potwor *p2 = Head;
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
	liczba++;
	licznik++;

}
void potwor::wyswietl(potwor *Head)
{
	potwor *p = Head;
	std::cout << "Head" << "->";
	if (Head != NULL)
	{

		while (p != NULL)
		{
			std::cout << p->x << "|" << p->y << "|" << p->stos1 << "|" << p->stos2  << "->";
			p = p->next;
		}
	}
	std::cout << "NULL" << std::endl;
}
bool potwor::wyrzuc(potwor *&Head, potwor *&wsk,int &liczba)
{
	potwor *p = Head;
	potwor *p1 = p;
	potwor* p2 = p;
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
				//liczba--;
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
					liczba--;
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
void potwor::wyczysc(potwor *&Head, int &liczba)
{
	
	
	
	while (Head != NULL)
	{
		potwor *p = Head;
		Head = Head->next;
		std::cout << " asd   " << std::endl;
		delete p;


	}
	liczba = 0;
	return;
	

}
void noweID(potwor * A, int licznik)
{
	A->ID = licznik;
}


void modul(double &x, double &y)
{
	if (x < 0)
	{
		x = -x;
	}
	if (y < 0)
	{
		y = -y;
	}
}
double odleglosc(naboj *&Head, potwor *&Head1)
{
	punkt A;
	double przeciw = 0;
	A.x = Head->x - Head1->x;
	A.y = Head->y - Head1->y;
	modul(A.x, A.y);  /// dlugosci przyprostokatnych
	przeciw = sqrt((A.x*A.x) + (A.y*A.y));
	return przeciw;
}

void potwor_naboj(naboj *&Head, potwor *& Head1, naboj *wsk, potwor *wsk1, int &liczba, bohater &A)
{
	
	double r = 25;
	while (wsk != NULL)
	{
		
		double odl = odleglosc(wsk, wsk1);
		if (odl < r) ///to usun naboj i potwora
		{
			//std::cout << "AS" << std::endl;
			wsk->x = -500;
			wsk1->x= -500;
			A.punkty = A.punkty + 100;
			liczba--;
			//std::cout << "                " << liczba << std::endl;
		}
		wsk = wsk->next;
	}


}



//=====================BOHATER SMIERC
double odleglosc1(bohater &A, potwor *&Head1)
{
	punkt B;
	double przeciw = 0;
	B.x = A.x - Head1->x;
	B.y = A.y - Head1->y;
	modul(B.x, B.y);  /// dlugosci przyprostokatnych
	przeciw = sqrt((B.x*B.x) + (B.y*B.y));
	return przeciw;
}
void smierc(bohater &A, potwor *&Head1, potwor *wsk1, bool &done)
{
	double r = 25;
	
	while (wsk1 != NULL)
	{

		double odl = odleglosc1(A, wsk1);
		if (odl < r) ///to usun naboj i potwora
		{
			
			std::cout << "smierc" << std::endl;
			wsk1->x = -50;
			A.zycie = A.zycie - 110;
			//done = true;
			//liczba--;
			//std::cout << "                " << liczba << std::endl;
		}
		wsk1 = wsk1->next;
	}
}




//===========================RESZTA
char* zamiana(int a)
{
	int b = a;
	int c = a;
	int licz = 0;
	while (b>0)
	{
		b = b / 10;
		licz++;
	}
	b = a;
	char* tab = new char[licz];
	for (int i = licz; i > 0; i--)
	{
		b = a;
		c = a;
		b = b / 10;
		b = b * 10;
		c = c - b;
		tab[i] = c;
	}
	return tab;
}