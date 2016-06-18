#include <string>
#include "move.h"
#include "recover.h"
#include <sstream>
using std::string;
using std::stringstream;

Recover::Recover(string nombre,string tipo,int precision,int usos,string descripcion):Move(nombre,tipo,precision,usos,descripcion){
}
void Recover::efecto(int& vida1,int& ataque1,int& defensa1,int& velocidad1,int& vida2,int& ataque2,int& defensa2,int& velocidad2,int debil){
	if(vida1<=25){
		vida1=vida1+25;
	}else{
		vida1=50;
	}
}
string Recover::toString(){
	return Move::toString();
}