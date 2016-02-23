#include "myszka.h"

float myszka::kat(int _x, int _y)
{
	double przec = 0;
	double a = (this->y * _y);
	double b = (this->x * _x);
	/*if (a < 0)
	{
		a = -a;
	}
	if (b < 0)
	{
		b = -b;
	}*/



	przec = sqrt(a + b);
	if ((this->x-_x)!=0 && (this->y-_y)!=0)
	{
		return (this->y-_y) / przec;
	}
	else
	{
		return 0;
	}
}
myszka::myszka()
{
	x = 0;
	y = 0;

}