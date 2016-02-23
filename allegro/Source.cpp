#include "bohater.h"
#include "mapa1.h"
#include "naglowki.h"
#include "myszka.h"
#include "naboje.h"
#include "menu.h"
using namespace std;





int main()
{

	srand(time(NULL));
	const int ScreenWidth = 800;
	const int ScreenHeight = 600;
	const int Speed = 5;
	int x = ScreenWidth / 2;
	int y = ScreenHeight / 2;
	const int FPS = 60.0;
	enum Direction{ UP, DOWN, LEFT, RIGHT };

	bool done = true;
	bool done1 = false;
	int draw = 1;

	int moveSpeed = 10;
	int dir = DOWN;

	int wys = 25;
	int szer = 25;
	int xyz = 5;

	float kat = 0;
	double t = 0, e = 0;
	int liczba = 0;
	float kat1 = 0;

	naboj *Head = NULL;
	naboj *wsk = Head;
	naboj *p1 = wsk;

	potwor *Head1 = NULL;
	potwor *wsk1 = Head1;
	potwor *p2 = wsk1;
	int licznik1 = 0;
	potwor *wsk3 = Head1;

	
	int zxc = 123;
	char tab[20];
	char tab1[20];
	

	int liczczas = 0;
	int czas = 0;


	int przeciwnicy = 3;

	int menu = 1;


	string locked;
	fstream plik;
	fstream plik1;
	fstream plik2;


	
	int locked1=0;
	bool zapis = true;
	int mapa = 1;
	bool odczyt = true;

	bool done2 = true;

	int nextMap = 1;
	bool stare = true;

	potwor* wsk10 = Head1;


	int licznik_ID = 1;

	ALLEGRO_DISPLAY *display;

	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "NOT INITIALIZE ALLEGRO 5", NULL, NULL);
	}
	al_set_new_display_flags(1);
	display = al_create_display(ScreenWidth, ScreenHeight);
	al_set_window_title(display, "Gra");
	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "NOT CREATE ALLEGRO WINDOW", NULL, NULL);
	}

	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	al_install_audio();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_acodec_addon();



	ALLEGRO_FONT *font = al_load_font("arial.ttf", 24, NULL);
	ALLEGRO_FONT *font1 = al_load_font("SEGA.ttf", 72, NULL);


	/*al_draw_text(font1, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "SEGA");
	al_flip_display();
	al_rest(2.0);*/

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font1, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "KOSTEK");
	al_flip_display();
	al_rest(2.0);


	
	
	
	

	bohater A(ScreenWidth / 2, ScreenHeight / 2, 100);
	postac * wskaznik = &A;
	myszka B;
	potwor L;
	//potwor G;


	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_COLOR electricBlue = al_map_rgb(44, 117, 255);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_EVENT_QUEUE *event_queue1 = al_create_event_queue();
	ALLEGRO_BITMAP *bitmapa = al_load_bitmap("mapa1.png");
	ALLEGRO_BITMAP *bitmapa1 = al_load_bitmap("postac2.png");
	ALLEGRO_BITMAP *bitmapa2 = al_load_bitmap("przeciwnik2.png");
	ALLEGRO_BITMAP *bitmapa3 = al_load_bitmap("punkt.png");
	ALLEGRO_BITMAP *bitmapa4 = al_load_bitmap("mapa1.png");
	ALLEGRO_BITMAP *bitmapa5 = al_load_bitmap("op.png");

	ALLEGRO_BITMAP *bitmapa6 = al_load_bitmap("menu1.png");
	ALLEGRO_BITMAP *bitmapa7 = al_load_bitmap("menu2.png");
	ALLEGRO_BITMAP *bitmapa8 = al_load_bitmap("menu3.png");

	ALLEGRO_BITMAP *bitmapa9 = al_load_bitmap("act1.png");
	ALLEGRO_BITMAP *bitmapa10 = al_load_bitmap("start.png");
	ALLEGRO_COLOR kolor = al_get_pixel(bitmapa4, A.x, A.y);
	ALLEGRO_COLOR kolor1 = al_map_rgb(250, 50, 150);
	

	al_reserve_samples(3);
	ALLEGRO_SAMPLE *song = al_load_sample("Miami2.ogg");
	 
	ALLEGRO_SAMPLE_INSTANCE *songInstance = al_create_sample_instance(song);
	
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());



	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue1, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_play_sample_instance(songInstance);
	
	

	while (done2)
	{
		al_get_keyboard_state(&keyState);
		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE))
		{
			done2 = false;
		}
		al_draw_scaled_bitmap(bitmapa10, 0, 0, 800, 600, 0, 0, 800, 600, 0);
		al_flip_display();

	}
	/*al_stop_sample_instance(songInstance);
	song = al_load_sample("HorseSteppin.ogg");
	songInstance = al_create_sample_instance(song);
	al_play_sample_instance(songInstance);*/

	while (!done1)
	{
		if (stare)
		{

			if (odczyt)
			{
				plik1.open("locked.txt", ios::in);
				if (plik1.good())
				{
					getline(plik1, locked);
				}
				else
				{
					cout << "as" << endl;
				}


				plik1.close();
				locked1 = atoi(locked.c_str());
				odczyt = false;
			}
			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && menu == 1)
			{
				menu = 2;
				//mapa = 1;
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
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && menu == 4)
			{
				menu = 5;
				if (locked1 == 1)
				{
					bitmapa9 = al_load_bitmap("locked2.png");
				}
				else
				{

					bitmapa9 = al_load_bitmap("act2.png");
				}

			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && menu == 5)
			{
				menu = 6;
				if (locked1 == 2 || locked1 == 1)
				{
					bitmapa9 = al_load_bitmap("locked3.png");
				}
				else
				{
					bitmapa9 = al_load_bitmap("act3.png");
				}
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) && menu == 6)
			{
				menu = 5;
				if (locked1 == 1)
				{
					bitmapa9 = al_load_bitmap("locked2.png");
				}
				else
				{
					bitmapa9 = al_load_bitmap("act2.png");
				}
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) && menu == 5)
			{
				menu = 4;
				bitmapa9 = al_load_bitmap("act1.png");
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_BACKSPACE) && (menu == 5 || menu == 4 || menu == 6))
			{
				menu = 1;
				//bitmapa9 = al_load_bitmap("act1.png");
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
			else if (menu == 4)
			{
				al_draw_scaled_bitmap(bitmapa9, 0, 0, 800, 600, 0, 0, 800, 600, 0);
			}
			else if (menu == 5)
			{
				al_draw_scaled_bitmap(bitmapa9, 0, 0, 800, 600, 0, 0, 800, 600, 0);
			}
			else if (menu == 6)
			{
				al_draw_scaled_bitmap(bitmapa9, 0, 0, 800, 600, 0, 0, 800, 600, 0);
			}


			al_flip_display();
			al_get_keyboard_state(&keyState);
			if (menu == 1 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{
				mapa = 1;
				bitmapa = al_load_bitmap("mapa5.png");
				A.reset();
				przeciwnicy = 3;
				done = false;
			}
			else if (menu == 2 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{
				//bitmapa9 = al_load_bitmap("act1.png");
				menu = 4;
			}
			else
			if (menu == 3 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{
				done1 = true;
			}
			else
			if (menu == 4 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{


				menu = 1;
				mapa = 1;
				bitmapa = al_load_bitmap("mapa5.png");
				przeciwnicy = 3;
				A.reset();
				done = false;
				menu = 1;
			}
			else
			if (menu == 5 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{
				//bitmapa9 = al_load_bitmap("act2.png");
				if (locked1 == 1)
				{
				}
				else{
					menu = 1;
					mapa = 2;
					bitmapa = al_load_bitmap("mapa1.png");
					przeciwnicy = 6;
					A.reset();
					done = false;
					menu = 1;
				}
			}
			else
			if (menu == 6 && al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{
				//bitmapa9 = al_load_bitmap("act3.png");


				if (locked1 == 1 || locked1 == 2)
				{
				}
				else{

					mapa = 3;
					bitmapa = al_load_bitmap("mapa7.png");
					A.reset();
					przeciwnicy = 9;
					done = false;
					menu = 1;
				}
			}
			al_rest(0.1);
			al_start_timer(timer);
		}
		else
		{
		//	cout << mapa << endl;
			if (mapa == 1)
			{
				cout << "hj" << endl;
				A.reset();
				bitmapa = al_load_bitmap("mapa1.png");
				mapa = 2;
				przeciwnicy = 6;
				done = false;
				menu = 1;
			}else 
			if (mapa == 2)
			{
				mapa = 3;
				bitmapa = al_load_bitmap("mapa7.png");
				A.reset();
				przeciwnicy = 9;
				done = false;
				menu = 1;
			}
			al_start_timer(timer);
		}

		//============================= petla 2

		while (!done)
		{
			
			//wskaznik->wypisz();
			
			ALLEGRO_EVENT events;
			al_wait_for_event(event_queue, &events);

			if (events.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (events.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					stare = true;
					potwor::wyczysc(Head1, liczba);
					bitmapa9 = al_load_bitmap("act1.png");
					A.reset();
				}
			}
			else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				done = true;

			
			
				//===============MYSZ
				

			al_wait_for_event(event_queue, &events);

			//al_stop_timer(timer);
			if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{

				t = events.mouse.x;
				e = events.mouse.y;
				
				naboj::dorzuc(Head, A.x, A.y, t, e, kat);



			}
			else

			//al_wait_for_event(event_queue1, &events);
			if (events.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				B.x = events.mouse.x;
				B.y = events.mouse.y;
			}
			//al_start_timer(timer);

			//===========STRZALKI
			if (events.type == ALLEGRO_EVENT_TIMER)
			{

			
				al_get_keyboard_state(&keyState);




				if (al_key_down(&keyState, ALLEGRO_KEY_S) && al_key_down(&keyState, ALLEGRO_KEY_D) && A.y + wys < ScreenHeight && A.x + szer<ScreenWidth && sprawdz1(A.x, A.y, kolor, kolor1, bitmapa4, keyState) && sprawdz2(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.y += moveSpeed*0.79;
					A.x += moveSpeed*0.79;
					draw = 8;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_W) && al_key_down(&keyState, ALLEGRO_KEY_D) && A.y > wys && A.x + szer<ScreenWidth && sprawdz(A.x, A.y, kolor, kolor1, bitmapa4, keyState) && sprawdz1(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.y -= moveSpeed*0.79;
					A.x += moveSpeed*0.79;
					draw = 6;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_S) && al_key_down(&keyState, ALLEGRO_KEY_A) && A.x >szer && A.y + wys<ScreenHeight && sprawdz2(A.x, A.y, kolor, kolor1, bitmapa4, keyState) && sprawdz3(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.y += moveSpeed*0.79;
					A.x -= moveSpeed*0.79;
					draw = 2;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_A) && al_key_down(&keyState, ALLEGRO_KEY_W) && A.x > szer && A.y > wys && sprawdz(A.x, A.y, kolor, kolor1, bitmapa4, keyState) && sprawdz3(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.y -= moveSpeed*0.79;
					A.x -= moveSpeed*0.79;
					draw = 4;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_S) && A.y + wys<ScreenHeight && sprawdz2(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.y += moveSpeed;
					draw = 1;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_W) && A.y > wys && sprawdz(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.y -= moveSpeed;
					draw = 5;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_D) && A.x + szer<ScreenWidth && sprawdz1(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.x += moveSpeed;
					draw = 7;

				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_A) && A.x > szer && sprawdz3(A.x, A.y, kolor, kolor1, bitmapa4, keyState))
				{
					A.x -= moveSpeed;
					draw = 3;

				}
				else
				{

					draw = 1;

				}



			}

			kat = atan2(B.y - A.y, B.x - A.x);

			wsk = Head;
			p1 = wsk;
			
			if (liczba < przeciwnicy)
			{
				potwor::dorzuc(Head1, liczba,licznik_ID);
				//potwor::wyswietl(Head1);
				
			}
			
			//cout << liczba << endl;



		
			//===================NABOJE
			wsk1 = Head1;
			while (wsk != NULL)
			{

				p1 = wsk;

				stosunek(Head, wsk->x, wsk->y, wsk->stos1, wsk->stos2, wsk->cw);

				al_draw_rotated_bitmap(bitmapa5, 20, 2.5, wsk->x, wsk->y, wsk->kat, 0);
				if (naboj::wyrzuc(Head, wsk))
				{
					wsk = Head;
				}



				if (Head != NULL)
				{
					wsk = wsk->next;
				}
				else
				{
					wsk = Head;
				}

				//====================potwory ruch
			}

			while (wsk1 != NULL)
			{
			
				p2 = wsk1;

				potworRuch(wsk1->x, wsk1->y, A.x, A.y);
				kat1 = atan2(A.y - wsk1->y, A.x - wsk1->x);
				
				al_draw_rotated_bitmap(bitmapa2, 25, 25, wsk1->x, wsk1->y, kat1, 0);

				if (potwor::wyrzuc(Head1, wsk1, liczba))
				{
					wsk1 = Head1;
				}



				if (Head1 != NULL)
				{
					wsk1 = wsk1->next;
				}
				else
				{
					wsk1 = Head1;
				}


			}

			// ===================== POTWORY_NABOJE

			wsk = Head;
			wsk1 = Head1;

			while (wsk1 != NULL)
			{


				potwor_naboj(Head, Head1, wsk, wsk1, liczba, A);



				wsk = Head;
				wsk1 = wsk1->next;

			}

			

			//=================BOHATER SMIERC
			wsk1 = Head1;

			while (wsk1 != NULL)
			{


				smierc(A, Head1, wsk1, done);
				
				
				wsk1 = wsk1->next;

			}









			//====================RYSOWANIE
			switch (draw)
			{
			case 1:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 0, 0, 30, 47, A.x, A.y, 0);
				//	al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 2:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 30, 0, 30, 47, A.x, A.y, 0);
				//al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 3:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//	al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 60, 0, 30, 47, A.x, A.y, 0);
				//	al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 4:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//	al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 90, 0, 30, 47, A.x, A.y, 0);
				//	al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 5:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//	al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 120, 0, 30, 47, A.x, A.y, 0);
				//al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 6:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//	al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 150, 0, 30, 47, A.x, A.y, 0);
				//al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 7:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 180, 0, 30, 47, A.x, A.y, 0);
				//al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			case 8:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 210, 0, 30, 47, A.x, A.y, 0);
				//al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			default:
				al_draw_rotated_bitmap(bitmapa1, 25, 25, A.x, A.y, kat, 0);
				//	al_draw_rotated_bitmap(bitmapa2, 25, 25, L.x, L.y, kat, 0);
				//al_draw_bitmap_region(bitmapa1, 0, 0, 30, 47, A.x, A.y, 0);
				//al_draw_bitmap_region(bitmapa2, 0, 0, 800, 600, 0, 0, 0);
				//al_draw_bitmap_region(bitmapa3, 0, 0, 5, 5, A.x / 5 + 17, A.y / 5 + 33, 0);
				al_flip_display();
				break;
			}

			

			sprintf_s(tab, "%d", A.punkty);
			sprintf_s(tab1, "%d", A.zycie);

			al_draw_text(font, al_map_rgb(44, 117, 255), 10, 10, ALLEGRO_ALIGN_LEFT, "Punkty: ");
			al_draw_text(font, al_map_rgb(44, 117, 255), 100, 10, ALLEGRO_ALIGN_LEFT, tab);
			al_draw_text(font, al_map_rgb(44, 117, 255), 10, 40, ALLEGRO_ALIGN_LEFT, "Zycie: ");
			al_draw_text(font, al_map_rgb(44, 117, 255), 100, 40, ALLEGRO_ALIGN_LEFT, tab1);
			al_flip_display();
			al_draw_scaled_bitmap(bitmapa, 0, 0, 800, 600, 0, 0, 800, 600, 0);

			//===================================================	
			if (A.zycie <= 0)
			{

				plik.open("statystyki.txt", ios::out | ios::app);
				if (plik.good())
				{
					if (mapa == 1)
					{
						plik << 1;
						plik << " -> ";
					}
					if (mapa == 2)
					{
						plik << 2;
						plik << " -> ";
					}
					if (mapa == 3)
					{
						plik << 3;
						plik << " -> ";
					}
					plik << A.punkty;
					plik << endl;
				}
				else
				{
					cout << " nie bardzo " << endl;
				}
				plik.close();
				if (mapa == 3)
				{
					potwor::wyczysc(Head1, liczba);
					A.reset();
					//mapa = 4;
					bitmapa9 = al_load_bitmap("act1.png");
					al_draw_text(font1, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "KONIEC");
					al_flip_display();
				}
				else
				{
					if (A.punkty < 200)
					{

						potwor::wyczysc(Head1, liczba);
						A.reset();
						bitmapa9 = al_load_bitmap("act1.png");
						al_draw_text(font1, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "KONIEC");
						al_flip_display();
					}
					else
					{
						potwor::wyczysc(Head1, liczba);
						A.reset();
						bitmapa9 = al_load_bitmap("act1.png");
						al_draw_text(font1, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "NEXT STAGE");
						al_flip_display();

					}
				}
				done = true;
				zapis = true;
				odczyt = true;
				wsk10 = Head1;
				while (wsk10 != NULL)
				{

					potwor::wyrzuc(Head1, wsk10, liczba);
					wsk10 = wsk10->next;

				}
				//wyswietl(Head1);
				//potwor::wyswietl(Head1);
				//cout <<"f" << endl;
				al_stop_timer(timer);
				al_rest(2.0);
				al_start_timer(timer);
			}
			else if (A.punkty >= 200 && zapis)
			{

			//	al_draw_text(font1, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "YOU WON");
				//al_flip_display();
				//done = true;
				//al_rest(2.0);

				plik2.open("locked.txt", ios::out);
				if (plik2.good())
				{
					if (mapa == 1)
					{
						plik2 << 2;
					}
					if (mapa == 2)
					{
						plik2 << 3;
					}
					if (mapa == 3)
					{
						plik2 << 3;
					}
					//cout << mapa << endl;
				}
				else
				{
					cout << "ad" << endl;
				}


				plik2.close();
				if (mapa == 1)
				{
				//	mapa = 2;
					stare = false;
				}
				if (mapa == 2)
				{
				//	mapa = 3;
					stare = false;
				}
				if (mapa == 3)
				{
					//	mapa = 3;
					stare = true;
				}
				zapis = false;
				
			}
			

		}
		al_stop_timer(timer);
		done = true;
	}




	al_destroy_bitmap(bitmapa1);
	al_destroy_bitmap(bitmapa2);
	al_destroy_bitmap(bitmapa3);
	al_destroy_bitmap(bitmapa4);
	al_destroy_bitmap(bitmapa5);
	al_destroy_bitmap(bitmapa6);
	al_destroy_bitmap(bitmapa7);
	al_destroy_bitmap(bitmapa8);
	al_destroy_bitmap(bitmapa9);
	al_destroy_bitmap(bitmapa10);
	al_destroy_sample_instance(songInstance);
	al_destroy_font(font1);
	al_destroy_font(font);
	al_destroy_sample(song);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
