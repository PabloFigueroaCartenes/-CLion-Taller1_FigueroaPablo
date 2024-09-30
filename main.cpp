//
// Created on 25-09-24.
//
#include "tableros.h"
#include "lectura.h"
int main() {
    MPP tablero1;
    MPP tablero2;
    string archivoEscenarios = "escenarios.txt";
    tablero1.llenarTablero(archivoEscenarios, 2);

    tablero2.insertar(0, 1, 7);
    tablero2.insertar(2, 3, 2);
    tablero2.insertar(3, 0, 5);
    tablero2.insertar(1, 2, 4);

    tablero1.desplegar();
    tablero2.desplegar();

    cout << parametrosXMatriz("escenarios.txt") << endl;
    cout << parametrosYMatriz("escenarios.txt") << endl;
    cout << parametrosXMatriz("fichas.txt") << endl;
    cout << parametrosYMatriz("fichas.txt") << endl;

    return 0;
}