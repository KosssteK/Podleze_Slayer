
#include "menu.h"

void menu1(ALLEGRO_KEYBOARD_STATE keyState, int &menu, bool &done, bool &done1, ALLEGRO_BITMAP *bitmapa6, ALLEGRO_BITMAP *bitmapa7, ALLEGRO_BITMAP *bitmapa8)
{
	
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && menu == 1)
	{
		menu = 2;
	}
	else if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && menu == 2)
	{
		menu = 3;
	}
	else if (al_key_down(&keyState, ALLEGRO_KEY_UP) && menu == 3)
	{
		menu = 2;
	}
	else if (al_key_down(&keyState, ALLEGRO_KEY_UP) && menu == 2)
	{
		menu = 1;
	}


	if (menu == 1)
	{
		al_draw_scaled_bitmap(bitmapa6, 0, 0, 800, 600, 0, 0, 800, 600, 0);
	}
	else if (menu == 2)
	{
		al_draw_scaled_bitmap(bitmapa7, 0, 0, 800, 600, 0, 0, 800, 600, 0);
	}
	else if (menu == 3)
	{
		al_draw_scaled_bitmap(bitmapa8, 0, 0, 800, 600, 0, 0, 800, 600, 0);
	}


	al_flip_display();
	//al_get_keyboard_state(&keyState);
	if (menu == 1 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
	{
		done = false;
	}
	else if (menu == 2 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
	{
		std::cout << "nic" << std::endl;
		//done = false;
	}
	else
	if (menu == 3 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
	{
		done1 = true;
	}
}

