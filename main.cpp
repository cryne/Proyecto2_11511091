#include <ncurses.h>
#include "pokemon.h"
#include "move.h"
#include "ataque.h"
#include "proteccion.h"
#include "recover.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include <thread>
#include <iostream>
#include <utility>
#include <chrono>
#include <functional>
#include <atomic>
using namespace std;
using std::string;
using std::vector;
void hilo();
void limpiar();
void limpiar_space(int,int,int,int);
void charmeleon(int);
void frogadier(int);
void pokebola();
void Combate(Pokemon,Pokemon);
vector<Pokemon*> generar_pokemons();
vector<Move*> generar_moves(string);
vector<Move*> oponent_moves(string);
int main(int argc, char const *argv[])
{
	initscr();
	srand(time(NULL));
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
	int s,enter,avanzar;
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
			vector<Pokemon*> pokemons=generar_pokemons();
			attron(COLOR_PAIR(2));
			limpiar();
			attroff(COLOR_PAIR(2));
			pokebola();
			int revision=1;
			Pokemon player;
			while(revision==1){
				attron(COLOR_PAIR(8));
				mvprintw(20,(y/2)-20,"Que pokemon desea elegir como su combatiente?");
				mvprintw(21,(y/2)-26,"(presione la tecla del numero del pokemon que desea elegir de la lista)");
				for (int i = 0; i < pokemons.size(); ++i)
				{
					mvprintw(22+(i)*5,(y/2)-8,"%d-%s",i,pokemons[i]->getNombre().c_str());
					mvprintw(23+(i)*5,(y/2)-8,"-Vida:%d",pokemons[i]->getVida());
					mvprintw(24+(i)*5,(y/2)-8,"-Ataque:%d",pokemons[i]->getAtaque());
					mvprintw(25+(i)*5,(y/2)-8,"-Defensa:%d",pokemons[i]->getDefensa());
					mvprintw(26+(i)*5,(y/2)-8,"-Velocidad:%d",pokemons[i]->getVelocidad());
				}
				int elegido=getch();
				if((elegido-48)<pokemons.size()&&(elegido-48)>=0){
					player=Pokemon(pokemons[elegido-48]);
					pokemons.erase(pokemons.begin()+(elegido-48));
					mvprintw(20,(y/2)-20,"Usted a elegido a %s como su combatiente (presione cualquier tecla para continuar)                                                             ",pokemons[elegido-48]->getNombre().c_str());	
					mvprintw(21,(y/2)-26,"                                                                                  ");
					revision=0;
					avanzar=getch();
				}else{
					mvprintw(20,(y/2)-20,"El numero que ingreso no existe en la lista como opcion(presione cualquier tecla para continuar)                                                             ");
					mvprintw(21,(y/2)-26,"                                                                                  ");
					avanzar=getch();
				}
				attroff(COLOR_PAIR(8));
			}
			vector<Move*> moves=generar_moves(player.getTipo());
			vector<Move*> playerMoves;
			playerMoves.push_back(new Ataque("Takle","Normal",100,15,"ataque simple que baja la vida del oponente con respecto a tu poder de ataque"));
			attron(COLOR_PAIR(2));
			limpiar();
			attroff(COLOR_PAIR(2));
			pokebola();
			attron(COLOR_PAIR(8));
			mvprintw(0,(y/2)-20,"(presione cualquier tecla para continuar)");
			mvprintw(20,(y/2)-20,"ahora se le mostrara la lista de movimientos que podra elegir,solo podra elegir 4");
			avanzar=getch();
			attroff(COLOR_PAIR(8));	
			while(revision==0){
				attron(COLOR_PAIR(2));
				limpiar();
				mvprintw(0,(y/2)-20,"(presione cualquier tecla para continuar)");
				attroff(COLOR_PAIR(2));
				pokebola();
				attron(COLOR_PAIR(8));
				for (int i = 0; i < moves.size(); ++i)
				{	
					mvprintw(22+(i)*2,(y/2)-8,"%d-%s",i,moves[i]->toString().c_str());
					mvprintw(23+(i)*2,(y/2)-8,"   Precision:%d  Usos:%d",moves[i]->getPrecision(),moves[i]->getUsos());
				}
				mvprintw(20,(y/2)-20,"Que movimiento desea elegir para que su pokemon lo aprenda?");
				mvprintw(21,(y/2)-26,"(presione la tecla del numero del movimiento que desea elegir de la lista)");
				int elegido=getch();
				if((elegido-48)<moves.size()&&(elegido-48)>=0){
					playerMoves.push_back(moves[elegido-48]);
					mvprintw(20,(y/2)-20,"Usted a elegido %s como nuevo movimiento para su pokemon                                                             ",moves[elegido-48]->getNombre().c_str());	
					mvprintw(21,(y/2)-26,"                                                                                  ");
					moves.erase(moves.begin()+(elegido-48));
					if(playerMoves.size()==4){
						mvprintw(20,(y/2)-20,"                                                                                  ");
						mvprintw(20,(y/2)-20,"Usted ya ha elegido los movimiento para su pokemon");
						revision=1;
					}
					avanzar=getch();
				}else{
					mvprintw(20,(y/2)-20,"El numero que ingreso no existe en la lista como opcion                                                             ");
					mvprintw(21,(y/2)-26,"                                                                                  ");
					avanzar=getch();
				}
				attroff(COLOR_PAIR(8));
			}
			player.setMoves(playerMoves);
			int oponent=rand()%pokemons.size();
			Pokemon oponente=Pokemon(pokemons[oponent]);
			oponente.setMoves(oponent_moves(oponente.getTipo()));
			thread main(hilo);
			thread run(Combate);
			Combate(player,oponente);
			run.join();
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
void Combate(Pokemon player,Pokemon cpu){

}
void hilo(){
	int x,y,z=2;
	getmaxyx(stdscr,y,x);
	while(true){
		attron(COLOR_PAIR(2));
		limpiar_space(0,0,23,46);
		limpiar_space(0,x-46,23,x);
		attroff(COLOR_PAIR(2));
		if((z%2)==0){
			charmeleon(0);
			frogadier(0);
		}else{
			charmeleon(1);
			frogadier(1);
		}
		z++;
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void limpiar_space(int y1,int x1,int y2,int x2){
	for (int i = y1; i <=y2; ++i)
	{
		for (int j = x1; j <= x2; ++i)
		{
			mvprintw(i,j," ");
		}
	}
}
vector<Move*> oponent_moves(string tipo){
	vector<Move*> moves;
	if(tipo=="Agua"){
		moves.push_back(new Proteccion("Protec","Normal",50,5,"movimiento que protege de todo ataque al usuario"));
		moves.push_back(new Recover("Recover","Normal",50,5,"movimientoque recupera vida del usuario(falla si el usuario no tiene dano alguno)"));
		moves.push_back(new Ataque("Aerial ace","Volador",100,8,"ataque aereo que nunca falla"));
		moves.push_back(new Ataque("Water pulse","Agua",99,5,"ataque que causa una onda acuatica que golpea al oponente"));
	}else if(tipo=="Fuego"){
		moves.push_back(new Proteccion("Protec","Normal",50,5,"movimiento que protege de todo ataque al usuario"));
		moves.push_back(new Recover("Recover","Normal",50,5,"movimientoque recupera vida del usuario(falla si el usuario no tiene dano alguno)"));
		moves.push_back(new Ataque("Thunder puch","Electrico",95,8,"ataque que causa una descarga electrica de un golpe"));
		moves.push_back(new Ataque("Flamethrower","Fuego",99,5,"ataque que lanza fuego al oponente"));
	}else{
		moves.push_back(new Proteccion("Protec","Normal",50,5,"movimiento que protege de todo ataque al usuario"));
		moves.push_back(new Recover("Recover","Normal",50,5,"movimientoque recupera vida del usuario(falla si el usuario no tiene dano alguno)"));
		moves.push_back(new Ataque("Rock tomb","Roca",90,10,"ataque que tumba rocas sobre el oponente"));
		moves.push_back(new Ataque("Leaf blade","Hoja",99,5,"ataque lanza hojas afiladas contra el oponente"));
	}
}
vector<Move*> generar_moves(string tipo){
	vector<Move*> moves;
	if(tipo=="Agua"){
		moves.push_back(new Ataque("Takle","Normal",100,15,"ataque simple que baja la vida del oponente con respecto a tu poder de ataque"));	
		moves.push_back(new Ataque("Rock tomb","Roca",90,10,"ataque que tumba rocas sobre el oponente"));
		moves.push_back(new Ataque("Aerial ace","Volador",100,8,"ataque aereo que nunca falla"));
		moves.push_back(new Ataque("Water pulse","Agua",99,5,"ataque que causa una onda acuatica que golpea al oponente"));
		moves.push_back(new Proteccion("Protec","Normal",50,5,"movimiento que protege de todo ataque al usuario"));
		moves.push_back(new Recover("Recover","Normal",50,5,"movimientoque recupera vida del usuario(falla si el usuario no tiene dano alguno)"));
	}else if(tipo=="Fuego"){
		moves.push_back(new Ataque("Takle","Normal",100,15,"ataque simple que baja la vida del oponente con respecto a tu poder de ataque"));		
		moves.push_back(new Ataque("Thunder puch","Electrico",95,8,"ataque que causa una descarga electrica de un golpe"));
		moves.push_back(new Ataque("Rock tomb","Roca",90,10,"ataque que tumba rocas sobre el oponente"));
		moves.push_back(new Ataque("Aerial ace","Volador",100,8,"ataque aereo que nunca falla"));
		moves.push_back(new Ataque("Flamethrower","Fuego",99,5,"ataque que lanza fuego al oponente"));
		moves.push_back(new Proteccion("Protec","Normal",50,5,"movimiento que protege de todo ataque al usuario"));
		moves.push_back(new Recover("Recover","Normal",50,5,"movimientoque recupera vida del usuario(falla si el usuario no tiene dano alguno)"));
	}else{
		moves.push_back(new Ataque("Takle","Normal",100,15,"ataque simple que baja la vida del oponente con respecto a tu poder de ataque"));	
		moves.push_back(new Ataque("Thunder puch","Electrico",95,8,"ataque que causa una descarga electrica de un golpe"));
		moves.push_back(new Ataque("Rock tomb","Roca",90,10,"ataque que tumba rocas sobre el oponente"));
		moves.push_back(new Ataque("Aerial ace","Volador",100,8,"ataque aereo que nunca falla"));
		moves.push_back(new Ataque("Leaf blade","Hoja",99,5,"ataque lanza hojas afiladas contra el oponente"));
		moves.push_back(new Proteccion("Protec","Normal",50,5,"movimiento que protege de todo ataque al usuario"));
		moves.push_back(new Recover("Recover","Normal",50,5,"movimientoque recupera vida del usuario(falla si el usuario no tiene dano alguno)"));
	}
	return moves;
}
vector<Pokemon*> generar_pokemons(){
	vector<Pokemon*> opciones;
	vector<Move*> moves1;
	vector<Move*> moves2;
	opciones.push_back(new Pokemon("Charmeleon","Fuego",50,17,10,80,moves1));
	opciones.push_back(new Pokemon("Frogadier","Agua",50,15,11,90,moves2));
	return opciones;
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
void charmeleon(int m){
attron(COLOR_PAIR(4));
	mvprintw(2+m,12,"  ");
	mvprintw(3+m,12,"    ");
	mvprintw(4+m,10,"      ");
	mvprintw(5+m,10,"      ");
	mvprintw(6+m,14,"  ");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(1));
	mvprintw(1+m,12,"  ");
	mvprintw(2+m,10,"  ");
	mvprintw(2+m,14,"  ");
	mvprintw(3+m,10,"  ");
	mvprintw(3+m,16,"  ");
	mvprintw(4+m,16,"  ");
	mvprintw(5+m,16,"  ");
	mvprintw(6+m,16,"  ");
	mvprintw(4+m,8,"  ");
	mvprintw(5+m,8,"  ");
	mvprintw(6+m,10,"  ");
	mvprintw(7+m,6,"    ");
	mvprintw(8+m,4,"    ");
	mvprintw(9+m,2,"  ");
	mvprintw(10+m,0,"  ");
	mvprintw(11+m,0,"  ");
	mvprintw(12+m,0,"  ");
	mvprintw(13+m,0,"  ");
	mvprintw(7+m,14,"  ");
	mvprintw(8+m,12,"  ");
	mvprintw(9+m,10,"  ");
	mvprintw(10+m,8,"  ");
	mvprintw(11+m,8,"  ");
	mvprintw(12+m,10,"                                ");
	mvprintw(11+m,14,"              ");
	mvprintw(11+m,30,"              ");
	mvprintw(10+m,18,"          ");
	mvprintw(10+m,30,"              ");
	mvprintw(9+m,20,"                      ");
	mvprintw(8+m,20,"                    ");
	mvprintw(7+m,22,"                  ");
	mvprintw(6+m,24,"              ");
	mvprintw(5+m,24,"            ");
	mvprintw(4+m,22,"          ");
	mvprintw(3+m,22,"        ");
	mvprintw(2+m,24,"    ");
	mvprintw(13+m,10,"                              ");
	mvprintw(13+m,2,"  ");
	mvprintw(14+m,2,"                                        ");
	mvprintw(15+m,4,"              ");
	mvprintw(15+m,20,"          ");
	mvprintw(15+m,34,"      ");
	mvprintw(15+m,42,"  ");
	mvprintw(16+m,6,"                      ");
	mvprintw(16+m,36,"  ");
	mvprintw(16+m,40,"    ");
	mvprintw(17+m,8,"            ");
	mvprintw(17+m,22,"        ");
	mvprintw(17+m,38,"    ");
	mvprintw(18+m,8,"                    ");
	mvprintw(18+m,30,"  ");
	mvprintw(19+m,10,"                    ");
	mvprintw(20+m,10,"          ");
	mvprintw(21+m,10,"  ");
	mvprintw(21+m,18,"  ");
	mvprintw(22+m,12,"      ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(3));
	mvprintw(6+m,12,"  ");
	mvprintw(7+m,12,"  ");
	mvprintw(14+m,24,"    ");
	mvprintw(15+m,22,"      ");
	mvprintw(16+m,24,"  ");
	mvprintw(17+m,24,"  ");
	mvprintw(18+m,22,"  ");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(5));
	mvprintw(7+m,10,"  ");
	mvprintw(8+m,8,"    ");
	mvprintw(9+m,4,"      ");
	mvprintw(10+m,2,"      ");
	mvprintw(11+m,2,"      ");
	mvprintw(12+m,2,"        ");
	mvprintw(12+m,14,"            ");
	mvprintw(12+m,28,"            ");
	mvprintw(13+m,4,"      ");
	mvprintw(13+m,12,"      ");
	mvprintw(13+m,20,"        ");
	mvprintw(13+m,32,"    ");
	mvprintw(14+m,4,"              ");
	mvprintw(14+m,20,"    ");
	mvprintw(14+m,36,"    ");
	mvprintw(15+m,6,"  ");
	mvprintw(15+m,10,"        ");
	mvprintw(15+m,36,"    ");
	mvprintw(16+m,10,"            ");
	mvprintw(16+m,40,"  ");
	mvprintw(17+m,10,"          ");
	mvprintw(18+m,12,"      ");
	mvprintw(18+m,26,"  ");
	mvprintw(19+m,12,"        ");
	mvprintw(20+m,14,"  ");
	mvprintw(21+m,14,"  ");
	mvprintw(11+m,18,"    ");
	mvprintw(11+m,24,"  ");
	mvprintw(11+m,34,"        ");
	mvprintw(10+m,22,"      ");
	mvprintw(10+m,32,"          ");
	mvprintw(9+m,22,"      ");
	mvprintw(9+m,30,"          ");
	mvprintw(8+m,22,"                ");
	mvprintw(7+m,24,"              ");
	mvprintw(6+m,28,"    ");
	mvprintw(6+m,34,"  ");
	mvprintw(5+m,26,"    ");
	mvprintw(4+m,24,"      ");
	mvprintw(3+m,24,"    ");
	attroff(COLOR_PAIR(5));
	move(0,0);
}
void frogadier(int m){
	int x,y;
	getmaxyx(stdscr,x,y);
	attron(COLOR_PAIR(1));
	mvprintw(5+m,y-2,"  ");
	mvprintw(6+m,y-2,"  ");
	mvprintw(4+m,y-6,"    ");
	mvprintw(5+m,y-8,"  ");
	mvprintw(6+m,y-10,"    ");
	mvprintw(7+m,y-14,"    ");
	mvprintw(6+m,y-18,"    ");
	mvprintw(7+m,y-6,"    ");
	mvprintw(8+m,y-6,"  ");
	mvprintw(9+m,y-8,"    ");
	mvprintw(10+m,y-10,"    ");
	mvprintw(10+m,y-16,"  ");
	mvprintw(11+m,y-16,"      ");
	mvprintw(1+m,y-34,"  ");
	mvprintw(2+m,y-36,"      ");
	mvprintw(2+m,y-24,"      ");
	mvprintw(3+m,y-38,"        ");
	mvprintw(3+m,y-28,"          ");
	mvprintw(4+m,y-38,"                    ");
	mvprintw(5+m,y-40,"                    ");
	mvprintw(6+m,y-40,"                    ");
	mvprintw(7+m,y-42,"                        ");
	mvprintw(8+m,y-44,"  ");
	mvprintw(8+m,y-40,"                      ");
	mvprintw(9+m,y-44,"      ");
	mvprintw(9+m,y-36,"                  ");
	mvprintw(10+m,y-42,"                      ");
	mvprintw(11+m,y-40,"                  ");
	mvprintw(12+m,y-36,"          ");
	mvprintw(13+m,y-36,"  ");
	mvprintw(13+m,y-22,"  ");
	mvprintw(13+m,y-18,"  ");
	mvprintw(12+m,y-18,"  ");
	mvprintw(14+m,y-38,"        ");
	mvprintw(14+m,y-24,"          ");
	mvprintw(15+m,y-38,"                          ");
	mvprintw(16+m,y-40,"                            ");
	mvprintw(17+m,y-44,"          ");
	mvprintw(17+m,y-32,"                  ");
	mvprintw(18+m,y-46,"  ");
	mvprintw(18+m,y-42,"      ");
	mvprintw(18+m,y-30,"                  ");
	mvprintw(19+m,y-46,"  ");
	mvprintw(19+m,y-40,"  ");
	mvprintw(19+m,y-36,"  ");
	mvprintw(19+m,y-28,"                  ");
	mvprintw(20+m,y-44,"    ");
	mvprintw(20+m,y-38,"    ");
	mvprintw(20+m,y-30,"  ");
	mvprintw(20+m,y-26,"        ");
	mvprintw(20+m,y-16,"    ");
	mvprintw(21+m,y-30,"  ");
	mvprintw(21+m,y-24,"  ");
	mvprintw(21+m,y-20,"  ");
	mvprintw(22+m,y-28,"    ");
	mvprintw(22+m,y-22,"  ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(6));
	mvprintw(5+m,y-28,"  ");
	mvprintw(6+m,y-30,"      ");
	mvprintw(7+m,y-30,"      ");
	mvprintw(8+m,y-30,"  ");
	mvprintw(9+m,y-42,"    ");
	mvprintw(10+m,y-40,"    ");
	mvprintw(11+m,y-36,"          ");
	mvprintw(10+m,y-24,"  ");
	mvprintw(14+m,y-36,"  ");
	mvprintw(15+m,y-36,"  ");
	mvprintw(16+m,y-38,"  ");
	mvprintw(17+m,y-38,"  ");
	mvprintw(15+m,y-32,"  ");
	mvprintw(16+m,y-32,"  ");
	mvprintw(17+m,y-30,"  ");
	mvprintw(16+m,y-28,"    ");
	mvprintw(14+m,y-22,"  ");
	mvprintw(15+m,y-22,"  ");
	mvprintw(16+m,y-22,"  ");
	mvprintw(17+m,y-24,"    ");
	mvprintw(18+m,y-24,"  ");
	mvprintw(15+m,y-18,"    ");
	mvprintw(16+m,y-18,"    ");
	mvprintw(17+m,y-18,"  ");
	mvprintw(18+m,y-20,"    ");
	mvprintw(19+m,y-16,"  ");
	attroff(COLOR_PAIR(6));
	attron(COLOR_PAIR(3));
	mvprintw(8+m,y-26,"  ");
	mvprintw(9+m,y-30,"  ");
	mvprintw(9+m,y-26,"  ");
	mvprintw(10+m,y-28,"  ");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(7));
	mvprintw(17+m,y-40,"  ");
	mvprintw(18+m,y-42,"    ");
	mvprintw(19+m,y-24,"  ");
	mvprintw(20+m,y-26,"    ");
	mvprintw(19+m,y-20,"  ");
	mvprintw(19+m,y-14,"  ");
	mvprintw(2+m,y-34,"  ");
	mvprintw(3+m,y-36,"    ");
	mvprintw(4+m,y-36,"      ");
	mvprintw(5+m,y-38,"        ");
	mvprintw(6+m,y-38,"      ");
	mvprintw(7+m,y-38,"  ");
	mvprintw(7+m,y-34,"  ");
	mvprintw(8+m,y-40,"  ");
	mvprintw(8+m,y-36,"    ");
	mvprintw(9+m,y-36,"      ");
	mvprintw(10+m,y-36,"        ");
	mvprintw(10+m,y-26,"  ");
	mvprintw(3+m,y-24,"    ");
	mvprintw(4+m,y-28,"        ");
	mvprintw(5+m,y-26,"    ");
	mvprintw(6+m,y-24,"  ");
	mvprintw(7+m,y-24,"    ");
	mvprintw(8+m,y-24,"    ");
	mvprintw(9+m,y-24,"    ");
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