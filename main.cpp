/******************************************************************************

Alumno: Eugenio Alejandro Cruz Hernandez
fecha: 30/03/2026
programa: calculo de rfc sin homoclave

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Diccionario de palabras NO permitidas
const vector<string> palabrasProhibidas = {
    "PENE", "VAGO", "LOCO"
};

// Verificar y modificar palabras prohibidas del diccionario
string corregirRFC(const string& rfc) {
    for (const string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
            return rfc.substr(0, 3) + "X"; // Reemplaza la última letra por 'X'
        }
    }
    return rfc;
}

// Función para obtener la primera vocal interna de una cadena
char obtenerPrimeraVocalInterna(const string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return c;
        }
    }
    return 'X'; // Si no se encuentra ninguna vocal interna
}

// Función principal para calcular el RFC
string calcularRFC(const string& nombre,
                   const string& apellidoPaterno,
                   const string& apellidoMaterno,
                   const string& fechaNacimiento) {

    string rfc;

    // Inicial y vocal interna del apellido paterno
    char letraInicial = apellidoPaterno[0];
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);

    // Inicial del apellido materno o 'X' si no hay
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';

    // Inicial del nombre
    char inicialNombre = nombre[0];

    // Obtener fecha (YYMMDD)
    string anio = fechaNacimiento.substr(2, 2);
    string mes = fechaNacimiento.substr(5, 2);
    string dia = fechaNacimiento.substr(8, 2);

    // Construcción del RFC
    rfc += letraInicial;
    rfc += primeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;

    // Corrección de palabras prohibidas
    rfc = corregirRFC(rfc);

    // Agregar fecha
    rfc += anio;
    rfc += mes;
    rfc += dia;

    return rfc;
}

int main() {
    string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    cout << "Introduce tu Nombre: ";
    getline(cin, nombre);

    cout << "Introduce tu apellido Paterno: ";
    getline(cin, apellidoPaterno);

    cout << "Introduce tu apellido Materno: ";
    getline(cin, apellidoMaterno);

    cout << "Introduce la fecha de nacimiento (YYYY/MM/DD): ";
    getline(cin, fechaNacimiento);

    string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);

    cout << "RFC: " << rfc << endl;

    return 0;
}