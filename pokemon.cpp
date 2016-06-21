#include <string>
#include <sstream>
#include "pokemon.h"
#include <iostream>
#include <vector>
#include <cstring>
using std::vector;
using std::string;
using std::stringstream;
using std::endl;

Pokemon::Pokemon(string nombre,string tipo,int vida,int ataque,int defensa,int velocidad,vector<Move*> moves){
	strcpy(this->nombre,nombre.c_str());
	strcpy(this->tipo,tipo.c_str());
	this->vida=vida;
	this->ataque=ataque;
	this->defensa=defensa;
	this->velocidad=velocidad;
	this->moves=moves;
}
Pokemon::Pokemon(){
}
Pokemon::Pokemon(const Pokemon* r){
	this->nombre=r->nombre;
	this->tipo=r->tipo;
	this->vida=r->vida;
	this->ataque=r->ataque;
	this->defensa=r->defensa;
	this->velocidad=r->velocidad;
	this->moves=r->moves;
}
string Pokemon::getNombre(){
	string nueva(nombre);
	return nueva;
}
int Pokemon::getVida(){
	return vida;
}
int Pokemon::getAtaque(){
	return ataque;
}
int Pokemon::getDefensa(){
	return defensa;
}
int Pokemon::getVelocidad(){
	return velocidad;
}
string Pokemon::getTipo(){
	string nueva(tipo);
	return nueva;
}
vector<Move*> Pokemon::getMoves(){
	return moves;
}
void Pokemon::setVida(int vida){
	this->vida=vida;
}
void Pokemon::setAtaque(int ataque){
	this->ataque=ataque;
}
void Pokemon::setDefensa(int defensa){
	this->defensa=defensa;
}
void Pokemon::setVelocidad(int velocidad){
	this->velocidad=velocidad;
}
void Pokemon::setMoves(vector<Move*> moves){
	this->moves=moves;
}
string Pokemon::toString(){
	stringstream ss;
	ss<<"Pokemon:"<<nombre<<endl;
	return ss.str();
}
