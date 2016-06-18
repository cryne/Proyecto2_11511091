#include <string>
#include <sstream>
#include "move.h"
#include "proteccion.h"
using std::string;
using std::stringstream;

Proteccion::Proteccion(string nombre,string tipo,int precision,int usos,string descripcion):Move(nombre,tipo,precision,usos,descripcion){
}
void Proteccion::efecto(int& vida1,int& ataque1,int& defensa1,int& velocidad1,int& vida2,int& ataque2,int& defensa2,int& velocidad2,int debil){
}
string Proteccion::toString(){
	return Move::toString();
}