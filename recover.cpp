#include <string>
#include "move.h"
#include "recover.h"
#include <sstream>
using std::string;
using std::stringstream;

Recover::Recover(string nombre,string tipo,int precision,int usos,string descripcion):Move(nombre,tipo,precision,usos,descripcion){
}
int Recover::efecto(int vida1,int ataque1,int vida2,int defensa2,int debil){
	if(vida1<=25){
		return vida1+25;
	}else{
		return 50;
	}
}
string Recover::toString(){
	return Move::toString();
}