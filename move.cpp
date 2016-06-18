#include <string>
#include <sstream>
#include <iostream>
#include "move.h"
using std::string;
using std::stringstream;
using std::endl;

Move::Move(string nombre,string tipo,int precision,int usos,string descripcion){
	this->nombre=nombre;
	this->tipo=tipo;
	this->precision=precision;
	this->usos=usos;
	this->descripcion=descripcion;
}
string Move::getNombre(){
	return nombre;
}
int Move::getPrecision(){
	return precision;
}
int Move::getUsos(){
	return usos;
}
string Move::getTipo(){
	return tipo;
}
string Move::getDescripcion(){
	return descripcion;
}
void Move::setUsos(int usos){
	this->usos=usos;
}
void Move::setPrecision(int precision){
	this->precision=precision;
}
void Move::efecto(int& vida1,int& ataque1,int& defensa1,int& velocidad1,int& vida2,int& ataque2,int& defensa2,int& velocidad2,int debil){
}
string Move::toString(){
	stringstream ss;
	ss<<nombre<<" -"<<tipo<<"-";
	return ss.str();
}