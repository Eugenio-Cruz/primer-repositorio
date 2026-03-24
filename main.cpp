/******************************************************************************

Alumno:Eugenio alejandro cruz hernandez
fecha: 24/03/2026
Descripcion: el codigo realiza el calculo de la edad de una pernona para determinar si es o no mayor de edad

*******************************************************************************/

#include <iostream>

int main() {
    int num;
    std::cout << "Escribe tu edad: " << std::endl;
    std::cin >> num;
    if (num >= 18) {
        std::cout << "Eres mayor de edad" << std::endl;
    } else {
        std::cout << "Lo siento eres menor de edad" << std::endl;
    }
    return 0;
}