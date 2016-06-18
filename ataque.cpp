#include <string>
#include <sstream>
#include "move.h"
#include "ataque.h"
using std::string;
using std::stringstream;

Ataque::Ataque(string nombre,string tipo,int precision,int usos,string descripcion):Move(nombre,tipo,precision,usos,descripcion){
}
void Ataque::efecto(int& vida1,int& ataque1,int& defensa1,int& velocidad1,int& vida2,int& ataque2,int& defensa2,int& velocidad2,int debil){
	if(debil==1){
		vida2=vida2-ataque1;
	}else if(debil==0){
		vida2=vida2-(ataque1-defensa2);
	}else{
		vida2=vida2-1;
	}
}
string Ataque::toString(){
	return Move::toString();
}