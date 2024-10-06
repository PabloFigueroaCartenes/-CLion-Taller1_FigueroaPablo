//
// Created on 25-09-24.
//
#include "tableros.h"
#include "lectura.h"
int main() {
    MPP tablero1;
    MPP tablero2;
    ficha fichas;
    string archivoEscenarios = "/home/amnesia/CLionProjects/-CLion-Taller1_FigueroaPablo/escenarios.txt";
    string archivoFichas = "/home/amnesia/CLionProjects/-CLion-Taller1_FigueroaPablo/fichas.txt";
    tablero1.llenarTablero(archivoEscenarios, 2);
    fichas.llenarFichas(archivoFichas);

    tablero2.insertar(0, 1, 7);
    tablero2.insertar(2, 3, 2);
    tablero2.insertar(3, 0, 5);
    tablero2.insertar(1, 2, 4);

    tablero1.desplegar();
    tablero2.desplegar();
    fichas.desplegar();

    cout << parametrosXMatriz(archivoEscenarios) << endl;
    cout << parametrosYMatriz(archivoEscenarios) << endl;
    cout << parametrosXMatriz(archivoFichas) << endl;
    cout << parametrosYMatriz(archivoFichas) << endl;

    return 0;
}