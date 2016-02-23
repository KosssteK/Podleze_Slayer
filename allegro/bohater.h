#ifndef bohater_h
#define bohater_h

#include "naglowki.h"
#include "naboje.h"
//include <string>

class postac
{
public:
	virtual void wypisz() = 0;
};
class bohater
	:public postac
{
public:
	int x;
	int y;
	int zycie;
	int punkty;
	//string sprite;
	//string nazwa;
	bohater(int _x, int _y, int _zycie);
	void reset();
	void wypisz();
	
};
class potwor
	:public postac
{
	int ID;
public:
	double x;
	double y;
	int zycie;

	double stos1;
	double stos2;
	potwor* next;
	potwor();
	static void dorzuc(potwor *&Head, int &liczba, int &licznik);
	static void wyswietl(potwor *Head);
	static bool wyrzuc(potwor *&Head, potwor *&wsk, int &liczba);
	static void wyczysc(potwor *&Head, int &liczba);
	//friend class bohater;
	void wypisz();
	friend void noweID(potwor * A,int licznik);

};
void noweID(potwor * A, int licznik);

void potworRuch(double &x, double &y, double X, double Y);
void modul(double &x, double &y);
double odleglosc(naboj *&Head, potwor *& Head1);
void potwor_naboj(naboj *&Head, potwor *& Head1, naboj *wsk, potwor *wsk1,int &liczba, bohater &A);
double odleglosc1(bohater &A, potwor *&Head1);
void smierc(bohater &A, potwor *&Head1, potwor *wsk1, bool &done);
char* zamiana(int a);

#endif