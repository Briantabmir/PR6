#include "caballos.h"


void Caballo::setNombreCaballo(string pNombreCaballo)
{
	nombreCaballo = pNombreCaballo;
}

void Caballo::setVelocidad(int pVelocidad)
{
	velocidad = pVelocidad;
}

void Caballo::setDistanciaRecorrido(int pdistanciaRecorrido)
{
	distanciaRecorrido = pdistanciaRecorrido;
}

void Caballo::setFusta(int pFusta)
{
	fusta = pFusta;
}

void Caballo::turno(int pDado)
{
	pDado = 1 + rand() % 6;
	setVelocidad(pDado);
	distanciaRecorrido += velocidad * pDado;
}

string Caballo::getNombreCaballo()
{
	return nombreCaballo;
}

int Caballo::getVelocidad()
{
	return velocidad;
}

int Caballo::getDistanciaRecorrido()
{
	return distanciaRecorrido;
}

int Caballo::getFusta()
{
	return fusta;
}



Caballo::Caballo(string pNombreCaballo, int pVelocidad, int pDistanciaRecorrido, int pFusta)
{
	nombreCaballo = pNombreCaballo;
	velocidad = pVelocidad;
	distanciaRecorrido = pDistanciaRecorrido;
	fusta = pFusta;
}

void Caballo::printStats(){

	cout << "El caballo " << getNombreCaballo() << " ha obtenido una velocidad de " << getVelocidad() << ". " << "Y recorre una distancia de " << getDistanciaRecorrido() << endl;
}

void Caballo::ganador(){

	cout << "El caballo " << getNombreCaballo() << " es el ganador de la carrera!!!" << endl;
}


