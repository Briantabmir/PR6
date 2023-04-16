#include "caballos.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int lanzarDado() {
    return rand() % 6 + 1; // Devuelve un número aleatorio entre 1 y 6
}

bool usarFusta() {
    string opcion;
    bool opcionValida = false;
    while (!opcionValida) {
        cout << "¿Quieres usar la fusta? (0 = no, 1 = sí): ";
        cin >> opcion;
        if (opcion == "0") {
            opcionValida = true;
            return false;
        }
        else if (opcion == "1") {
            opcionValida = true;
            int resultado = rand() % 2; // Genera un número aleatorio entre 0 y 1
            if (resultado == 0) {
                cout << "Has usado la fusta pero no ha tenido efecto!" << endl;
                return false;
            }
            else {
                cout << "Has usado la fusta y tu velocidad se ha duplicado!" << endl;
                return true;
            }
        }
        else {
            cout << "Opción inválida. Por favor, ingresa 0 o 1." << endl;
        }
    }
}


void turno(Caballo& caballo, int& dado) {
    dado = lanzarDado();
    cout << "El caballo " << caballo.getNombreCaballo() << " ha lanzado el dado y ha obtenido un " << dado << endl;

    //Cálculo de la velocidad
    caballo.setVelocidad(caballo.getVelocidad() + dado);
    cout << "La velocidad de " << caballo.getNombreCaballo() << " es ahora de " << caballo.getVelocidad() << endl;

    bool fustaUsada = false;
    while (caballo.getFusta() > 0 && !fustaUsada) {
        //uso de la fusta
        int opcion;
        cout << "Quieres usar la fusta? (0 = no, 1 = si): ";
        cin >> opcion;

        if (opcion == 1) {
            int resultado = rand() % 2; // Genera un número aleatorio entre 0 y 1
            if (resultado == 0) {
                cout << "Has usado la fusta pero no ha tenido efecto!" << endl;
                caballo.setFusta(caballo.getFusta() - 1);
            }
            else {
                cout << "Has usado la fusta y tu velocidad se ha duplicado!" << endl;
                caballo.setVelocidad(caballo.getVelocidad() * 2);
                caballo.setFusta(caballo.getFusta() - 1);
                fustaUsada = true;
            }
        }
        else {
            fustaUsada = true;
        }
    }

    //Cálculo de la distancia recorrida
    caballo.setDistanciaRecorrido(caballo.getDistanciaRecorrido() + caballo.getVelocidad() * 100);
    cout << "La distancia recorrida por " << caballo.getNombreCaballo() << " es ahora de " << caballo.getDistanciaRecorrido() << " metros" << endl;

}


int main() {  

        srand(time(NULL));


        Caballo caballo1("Troya", 0, 0, 1);
        Caballo caballo2("Pegaso", 0, 0, 1);

        // Turnos
        int dado;
        for (int i = 0; i < 5; ++i){
            std::cout << "___________*Turno " << (i + 1) << "*__________" << std::endl;

            turno(caballo1, dado);
            turno(caballo2, dado);
        }

        // Resultado final
        
        if (caballo1.getDistanciaRecorrido() > caballo2.getDistanciaRecorrido())
        {
            std::cout << caballo1.getNombreCaballo() << " ha ganado con una distancia de " << caballo1.getDistanciaRecorrido() << " km" << std::endl;
        }
        else if (caballo1.getDistanciaRecorrido() < caballo2.getDistanciaRecorrido())
        {
            std::cout << caballo2.getNombreCaballo() << " ha ganado con una distancia de " << caballo2.getDistanciaRecorrido() << " km" << std::endl;
        }
        else
        {
            std::cout << "Empate con una distancia de " << caballo1.getDistanciaRecorrido() << " km" << std::endl;
        }

        return 0;
        


 }
 















