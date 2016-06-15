#include <ncurses.h>
#include "pokemon.h"
#include "move.h"
#include <vector>
using std::vector;
void limpiar();
void charmeleon();
void frogadier();
void pokebola();
vector<Pokemon*> generar_pokemons();
int main(int argc, char const *argv[])
{
	initscr();
	noecho();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_WHITE,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_YELLOW);
	init_pair(4,COLOR_WHITE,COLOR_MAGENTA);
	init_pair(5,COLOR_WHITE,COLOR_RED);
	init_pair(6,COLOR_WHITE,COLOR_CYAN);
	init_pair(7,COLOR_WHITE,COLOR_BLUE);
	init_pair(8,COLOR_BLACK,COLOR_WHITE);
	attron(COLOR_PAIR(2));
	limpiar();
	attroff(COLOR_PAIR(2));
	int s,enter;
	printw("Presione cualquier tecla diferente ESC para iniciar el programa");
	while((s=getch()!=27)){
		attron(COLOR_PAIR(2));
		limpiar();
		attroff(COLOR_PAIR(2));
		pokebola();
		int x,y;
		getmaxyx(stdscr,x,y);
		attron(COLOR_PAIR(8));
    	mvprintw(20,(y/2)-16,"*-----------------------------*");
    	mvprintw(21,(y/2)-16,"|BIENVENIDO AL COMBATE POKEMON|");
    	mvprintw(22,(y/2)-16,"*-----------------------------*");
    	mvprintw(23,(y/2)-16,"|   (ENTER)Iniciar Combate    |");
    	mvprintw(24,(y/2)-16,"|                             |");
    	mvprintw(25,(y/2)-16,"|     (B)Cargar Combate       |");
    	mvprintw(26,(y/2)-16,"|                             |");
    	mvprintw(27,(y/2)-16,"|         (ESC)salir          |");
    	mvprintw(28,(y/2)-16,"|                             |");
    	mvprintw(29,(y/2)-16,"*-----------------------------*");
		attroff(COLOR_PAIR(8));
		enter=getch();
		if(enter==10){
			attron(COLOR_PAIR(8));
			mvprintw(20,(y/2)-16,"hola");
			attroff(COLOR_PAIR(8));
			s=getch();
			refresh();
		}else if (enter==98)
		{
			attron(COLOR_PAIR(8));
			mvprintw(20,(y/2)-16,"adios");
			attroff(COLOR_PAIR(8));
		}
	}
	endwin();
	return 0;
}
vector<Pokemon*> generar_pokemons(){
	vector<Pokemon*> opciones;
	opciones.push_back(new Pokemon("Charmeleon","Fuego",400,64,58,80,));
}
void pokebola(){
	int x,y;
	getmaxyx(stdscr,x,y);
	attron(COLOR_PAIR(1));
	mvprintw(5,(y/2)-4,"        ");
	mvprintw(6,(y/2)-8,"                ");
	mvprintw(7,(y/2)-10,"                    ");
	mvprintw(8,(y/2)-12,"                        ");
	mvprintw(9,(y/2)-12,"                        ");
	mvprintw(10,(y/2)-14,"            ");
	mvprintw(10,(y/2)+2,"            ");
	mvprintw(11,(y/2)-14,"          ");
	mvprintw(11,(y/2)+4,"          ");
	mvprintw(12,(y/2)-14,"          ");
	mvprintw(12,(y/2)+4,"          ");
	mvprintw(13,(y/2)-14,"  ");
	mvprintw(13,(y/2)-4,"  ");
	mvprintw(13,(y/2)+2,"  ");
	mvprintw(13,(y/2)+12,"  ");
	mvprintw(14,(y/2)-12,"  ");
	mvprintw(14,(y/2)-2,"    ");
	mvprintw(14,(y/2)+10,"  ");
	mvprintw(15,(y/2)-12,"  ");
	mvprintw(15,(y/2)+10,"  ");
	mvprintw(16,(y/2)-10,"  ");
	mvprintw(16,(y/2)+8,"  ");
	mvprintw(17,(y/2)-8,"    ");
	mvprintw(17,(y/2)+4,"    ");
	mvprintw(18,(y/2)-4,"        ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(5));
	mvprintw(6,(y/2)-4,"        ");
	mvprintw(7,(y/2)-8,"                ");
	mvprintw(8,(y/2)-10,"                    ");
	mvprintw(9,(y/2)-10,"        ");
	mvprintw(9,(y/2)+2,"        ");
	mvprintw(10,(y/2)-12,"        ");
	mvprintw(10,(y/2)+4,"        ");
	attroff(COLOR_PAIR(5));
	move(0,0);
}
void charmeleon(){
attron(COLOR_PAIR(4));
	mvprintw(2,12,"  ");
	mvprintw(3,12,"    ");
	mvprintw(4,10,"      ");
	mvprintw(5,10,"      ");
	mvprintw(6,14,"  ");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(1));
	mvprintw(1,12,"  ");
	mvprintw(2,10,"  ");
	mvprintw(2,14,"  ");
	mvprintw(3,10,"  ");
	mvprintw(3,16,"  ");
	mvprintw(4,16,"  ");
	mvprintw(5,16,"  ");
	mvprintw(6,16,"  ");
	mvprintw(4,8,"  ");
	mvprintw(5,8,"  ");
	mvprintw(6,10,"  ");
	mvprintw(7,6,"    ");
	mvprintw(8,4,"    ");
	mvprintw(9,2,"  ");
	mvprintw(10,0,"  ");
	mvprintw(11,0,"  ");
	mvprintw(12,0,"  ");
	mvprintw(13,0,"  ");
	mvprintw(7,14,"  ");
	mvprintw(8,12,"  ");
	mvprintw(9,10,"  ");
	mvprintw(10,8,"  ");
	mvprintw(11,8,"  ");
	mvprintw(12,10,"                                ");
	mvprintw(11,14,"              ");
	mvprintw(11,30,"              ");
	mvprintw(10,18,"          ");
	mvprintw(10,30,"              ");
	mvprintw(9,20,"                      ");
	mvprintw(8,20,"                    ");
	mvprintw(7,22,"                  ");
	mvprintw(6,24,"              ");
	mvprintw(5,24,"            ");
	mvprintw(4,22,"          ");
	mvprintw(3,22,"        ");
	mvprintw(2,24,"    ");
	mvprintw(13,10,"                              ");
	mvprintw(13,2,"  ");
	mvprintw(14,2,"                                        ");
	mvprintw(15,4,"              ");
	mvprintw(15,20,"          ");
	mvprintw(15,34,"      ");
	mvprintw(15,42,"  ");
	mvprintw(16,6,"                      ");
	mvprintw(16,36,"  ");
	mvprintw(16,40,"    ");
	mvprintw(17,8,"            ");
	mvprintw(17,22,"        ");
	mvprintw(17,38,"    ");
	mvprintw(18,8,"                    ");
	mvprintw(18,30,"  ");
	mvprintw(19,10,"                    ");
	mvprintw(20,10,"          ");
	mvprintw(21,10,"  ");
	mvprintw(21,18,"  ");
	mvprintw(22,12,"      ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(3));
	mvprintw(6,12,"  ");
	mvprintw(7,12,"  ");
	mvprintw(14,24,"    ");
	mvprintw(15,22,"      ");
	mvprintw(16,24,"  ");
	mvprintw(17,24,"  ");
	mvprintw(18,22,"  ");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(5));
	mvprintw(7,10,"  ");
	mvprintw(8,8,"    ");
	mvprintw(9,4,"      ");
	mvprintw(10,2,"      ");
	mvprintw(11,2,"      ");
	mvprintw(12,2,"        ");
	mvprintw(12,14,"            ");
	mvprintw(12,28,"            ");
	mvprintw(13,4,"      ");
	mvprintw(13,12,"      ");
	mvprintw(13,20,"        ");
	mvprintw(13,32,"    ");
	mvprintw(14,4,"              ");
	mvprintw(14,20,"    ");
	mvprintw(14,36,"    ");
	mvprintw(15,6,"  ");
	mvprintw(15,10,"        ");
	mvprintw(15,36,"    ");
	mvprintw(16,10,"            ");
	mvprintw(16,40,"  ");
	mvprintw(17,10,"          ");
	mvprintw(18,12,"      ");
	mvprintw(18,26,"  ");
	mvprintw(19,12,"        ");
	mvprintw(20,14,"  ");
	mvprintw(21,14,"  ");
	mvprintw(11,18,"    ");
	mvprintw(11,24,"  ");
	mvprintw(11,34,"        ");
	mvprintw(10,22,"      ");
	mvprintw(10,32,"          ");
	mvprintw(9,22,"      ");
	mvprintw(9,30,"          ");
	mvprintw(8,22,"                ");
	mvprintw(7,24,"              ");
	mvprintw(6,28,"    ");
	mvprintw(6,34,"  ");
	mvprintw(5,26,"    ");
	mvprintw(4,24,"      ");
	mvprintw(3,24,"    ");
	attroff(COLOR_PAIR(5));
	move(0,0);
}
void frogadier(){
	int x,y;
	getmaxyx(stdscr,x,y);
	attron(COLOR_PAIR(1));
	mvprintw(5,y-2,"  ");
	mvprintw(6,y-2,"  ");
	mvprintw(4,y-6,"    ");
	mvprintw(5,y-8,"  ");
	mvprintw(6,y-10,"    ");
	mvprintw(7,y-14,"    ");
	mvprintw(6,y-18,"    ");
	mvprintw(7,y-6,"    ");
	mvprintw(8,y-6,"  ");
	mvprintw(9,y-8,"    ");
	mvprintw(10,y-10,"    ");
	mvprintw(10,y-16,"  ");
	mvprintw(11,y-16,"      ");
	mvprintw(1,y-34,"  ");
	mvprintw(2,y-36,"      ");
	mvprintw(2,y-24,"      ");
	mvprintw(3,y-38,"        ");
	mvprintw(3,y-28,"          ");
	mvprintw(4,y-38,"                    ");
	mvprintw(5,y-40,"                    ");
	mvprintw(6,y-40,"                    ");
	mvprintw(7,y-42,"                        ");
	mvprintw(8,y-44,"  ");
	mvprintw(8,y-40,"                      ");
	mvprintw(9,y-44,"      ");
	mvprintw(9,y-36,"                  ");
	mvprintw(10,y-42,"                      ");
	mvprintw(11,y-40,"                  ");
	mvprintw(12,y-36,"          ");
	mvprintw(13,y-36,"  ");
	mvprintw(13,y-22,"  ");
	mvprintw(13,y-18,"  ");
	mvprintw(12,y-18,"  ");
	mvprintw(14,y-38,"        ");
	mvprintw(14,y-24,"          ");
	mvprintw(15,y-38,"                          ");
	mvprintw(16,y-40,"                            ");
	mvprintw(17,y-44,"          ");
	mvprintw(17,y-32,"                  ");
	mvprintw(18,y-46,"  ");
	mvprintw(18,y-42,"      ");
	mvprintw(18,y-30,"                  ");
	mvprintw(19,y-46,"  ");
	mvprintw(19,y-40,"  ");
	mvprintw(19,y-36,"  ");
	mvprintw(19,y-28,"                  ");
	mvprintw(20,y-44,"    ");
	mvprintw(20,y-38,"    ");
	mvprintw(20,y-30,"  ");
	mvprintw(20,y-26,"        ");
	mvprintw(20,y-16,"    ");
	mvprintw(21,y-30,"  ");
	mvprintw(21,y-24,"  ");
	mvprintw(21,y-20,"  ");
	mvprintw(22,y-28,"    ");
	mvprintw(22,y-22,"  ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(6));
	mvprintw(5,y-28,"  ");
	mvprintw(6,y-30,"      ");
	mvprintw(7,y-30,"      ");
	mvprintw(8,y-30,"  ");
	mvprintw(9,y-42,"    ");
	mvprintw(10,y-40,"    ");
	mvprintw(11,y-36,"          ");
	mvprintw(10,y-24,"  ");
	mvprintw(14,y-36,"  ");
	mvprintw(15,y-36,"  ");
	mvprintw(16,y-38,"  ");
	mvprintw(17,y-38,"  ");
	mvprintw(15,y-32,"  ");
	mvprintw(16,y-32,"  ");
	mvprintw(17,y-30,"  ");
	mvprintw(16,y-28,"    ");
	mvprintw(14,y-22,"  ");
	mvprintw(15,y-22,"  ");
	mvprintw(16,y-22,"  ");
	mvprintw(17,y-24,"    ");
	mvprintw(18,y-24,"  ");
	mvprintw(15,y-18,"    ");
	mvprintw(16,y-18,"    ");
	mvprintw(17,y-18,"  ");
	mvprintw(18,y-20,"    ");
	mvprintw(19,y-16,"  ");
	attroff(COLOR_PAIR(6));
	attron(COLOR_PAIR(3));
	mvprintw(8,y-26,"  ");
	mvprintw(9,y-30,"  ");
	mvprintw(9,y-26,"  ");
	mvprintw(10,y-28,"  ");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(7));
	mvprintw(17,y-40,"  ");
	mvprintw(18,y-42,"    ");
	mvprintw(19,y-24,"  ");
	mvprintw(20,y-26,"    ");
	mvprintw(19,y-20,"  ");
	mvprintw(19,y-14,"  ");
	mvprintw(2,y-34,"  ");
	mvprintw(3,y-36,"    ");
	mvprintw(4,y-36,"      ");
	mvprintw(5,y-38,"        ");
	mvprintw(6,y-38,"      ");
	mvprintw(7,y-38,"  ");
	mvprintw(7,y-34,"  ");
	mvprintw(8,y-40,"  ");
	mvprintw(8,y-36,"    ");
	mvprintw(9,y-36,"      ");
	mvprintw(10,y-36,"        ");
	mvprintw(10,y-26,"  ");
	mvprintw(3,y-24,"    ");
	mvprintw(4,y-28,"        ");
	mvprintw(5,y-26,"    ");
	mvprintw(6,y-24,"  ");
	mvprintw(7,y-24,"    ");
	mvprintw(8,y-24,"    ");
	mvprintw(9,y-24,"    ");
	attroff(COLOR_PAIR(7));
	move(0,0);
}
void limpiar(){
	int x,y;
	getmaxyx(stdscr,x,y);
	for (int i = 0; i <y ; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			mvprintw(j,i," ");
		}
	}
	move(0,0);
}