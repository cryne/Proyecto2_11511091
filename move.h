#pragma once
#include <string>
using std::string;

class Move
{
	string nombre;
	string tipo;
	int precision,usos;
	string descripcion;
public:
	Move(string,string,int,int,string);
	string getNombre();
	int getPrecision();
	int getUsos();
	string getTipo();
	string getDescripcion();
	void setUsos(int);
	void setPrecision(int);
	virtual int efecto(int,int,int,int,int);
	virtual string toString();
};
