#ifndef mapa1_h
#define mapa1_h
#include "naboje.h"
#include "naglowki.h"
#include "bohater.h"
class ALLEGRO_COLOUR
	:public ALLEGRO_COLOR
{
public:
	bool operator == (const ALLEGRO_COLOUR &v)
	{
		if (this->r == v.r && this->g == v.g && this->b == v.b && this->a == v.a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	ALLEGRO_COLOUR & operator =(const ALLEGRO_COLOR &v)
	{
		ALLEGRO_COLOUR A;
		A.r = v.r;
		A.g = v.g;
		A.b = v.b;
		A.a = v.a;
		return A;
	}

};

class statystyki
	:private punkt
{
	friend void zmien(statystyki &k);
};
void zmien(statystyki &k);









bool sprawdz(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState);
bool sprawdz1(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState);
bool sprawdz2(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState);
bool sprawdz3(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState);


#endif