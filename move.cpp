#include <string>
#include <sstream>
#include <iostream>
#include <cstring>
#include "move.h"
using std::string;
using std::stringstream;
using std::endl;

Move::Move(string nombre,string tipo,int precision,int usos,string descripcion){
	strcpy(this->nombre,nombre.c_str());
	strcpy(this->tipo,tipo.c_str());
	this->precision=precision;
	this->usos=usos;
	strcpy(this->descripcion,descripcion.c_str());
}
string Move::getNombre(){
	string nueva(nombre);
	return nueva;
}
int Move::getPrecision(){
	return precision;
}
int Move::getUsos(){
	return usos;
}
string Move::getTipo(){
	string nueva(tipo);
	return nueva;
}
string Move::getDescripcion(){
	string nueva(descripcion);
	return nueva;
}
void Move::setUsos(int usos){
	this->usos=usos;
}
void Move::setPrecision(int precision){
	this->precision=precision;
}
int Move::efecto(int vida1,int ataque1,int vida2,int defensa2,int debil){
}
string Move::toString(){
	stringstream ss;
	ss<<nombre<<" -"<<tipo<<"-";
	return ss.str();
}