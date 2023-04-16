#include <iostream>
using namespace std;


class Caballo
{
private:		// Atributos del caballo
	string nombreCaballo;
	int velocidad;
	int distanciaRecorrido;
	int fusta; //Nitro
	

public:		   
	
	// Constructor
	Caballo(string pNombreCaballo, int pVelocidad, int pDistanciaRecorrido, int pFusta);

	// Métodos - Setter (guardamos los valores en los atributos)
	void setNombreCaballo(string pNombreCaballo);
	void setVelocidad(int pVelocidad);
	void setDistanciaRecorrido(int pdistanciaRecorrido);
	void setFusta(int pFusta);
	void turno(int pDado);

	
	// Getters 
	string getNombreCaballo();
	int getVelocidad();
	int getDistanciaRecorrido();
	int getFusta();
	
	

	// Methods
	void printStats();
	void ganador();
	

};



