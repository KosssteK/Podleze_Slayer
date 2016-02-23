#include "mapa1.h"
#include "bohater.h"

enum Direction{ UP, DOWN, LEFT, RIGHT };

const int wys = 50;
const int szer = 50;

bool sprawdz(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState)
{
	
	kolor = al_get_pixel(bitmapa4, x, y - 5);
	if (al_key_down(&keyState, ALLEGRO_KEY_UP) && kolor.r == kolor1.r && kolor.g == kolor1.g && kolor.b == kolor1.b && kolor.a == kolor1.a)
	{
		return false;
	}
	return true;
}
bool sprawdz1(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState)
{
	kolor = al_get_pixel(bitmapa4, x + szer + 5, y);
	if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && kolor.r == kolor1.r && kolor.g == kolor1.g && kolor.b == kolor1.b && kolor.a == kolor1.a)
	{
		return false;
	}
	return true;
}
bool sprawdz2(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState)
{
	kolor = al_get_pixel(bitmapa4, x, y+ wys + 5);
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && kolor.r == kolor1.r && kolor.g == kolor1.g && kolor.b == kolor1.b && kolor.a == kolor1.a)
	{
		return false;
	}
	return true;
}
bool sprawdz3(int x, int y, ALLEGRO_COLOR kolor, ALLEGRO_COLOR kolor1, ALLEGRO_BITMAP* bitmapa4, ALLEGRO_KEYBOARD_STATE keyState)
{
	kolor = al_get_pixel(bitmapa4, x - 5, y);
	if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) && kolor.r == kolor1.r && kolor.g == kolor1.g && kolor.b == kolor1.b && kolor.a == kolor1.a)
	{
		return false;
	}
	return true;
}
void zmien(statystyki &k)
{
	k.x = 100;
	k.y = 200;
}
