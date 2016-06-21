#pragma once
#include <string>
using std::string;

class Move
{
	char* nombre=new char(15);
	char* tipo=new char(15);
	int precision,usos;
	char* descripcion=new char(50);
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
