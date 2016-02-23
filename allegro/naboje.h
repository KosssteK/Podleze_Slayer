#ifndef naboje_h
#define naboje_h
#include "naglowki.h"


class punkt
{
public:
	double x;
	double y;
	punkt();
	punkt(double x, double y);
};

class naboj
	:public punkt
{
public:
	double a;
	double b;
	float kat;
	double stos1;
	double stos2;
	int cw;
	naboj *next;
	naboj();
	naboj(double x, double y, double a, double b,float kat);
	static double poruszaj(naboj * Head, double &x, double &y, double stos1, double stos2,int cw, float kat);
	static void dorzuc(naboj *&Head, double x, double y, double a, double b,float kat);
	static void wyswietl(naboj *Head);
	static bool wyrzuc(naboj *&Head,naboj *&wsk);

};
class prosta
{
public:
	double a;
	double b;
	prosta();
	prosta(double a, double b);
	
};

prosta rownanie(double x, double y, double a, double b);
punkt wspPkt(prosta A);
void stosunek(naboj *Head, double &x, double &y, double a, double b, int cw);


template <class Klasa>
void wyswietl(Klasa *Head);

#endif