//
// Created on 06-10-24.
//

#ifndef CONTROL1_1_MENU_H
#define CONTROL1_1_MENU_H
#include "tableros.h"


void dividor(int n) {
    for(int i = 0; i < n; i++) {
        cout << "#";
    }
    cout << "" << endl;
}
void sangria(int n) {
    for(int i = 0; i < n; i++) {
        cout << "  ";
    }
}
int menu(string archivoEscenarios, string archivoFichas) {
    MPP tablero1;
    MPP tablero2;
    ficha fichas;
    fichas.llenarFichas(archivoFichas);

    string seleccion;
    regex patron1(R"([1-4])");
    dividor(36);
    sangria(12);
    cout << "Menu Principal" << endl;
    dividor(36);
    cout << "Ingrese su opcion:" << endl;
    cout << "1) Comenzar Combate" << endl;
    cout << "2) Cambiar fichas del equipo" << endl;
    cout << "3) Cambiar posicion de las fichas" << endl;
    cout << "4) Cerrar Juego" << endl;
    cout << "Ingrese su seleccion: ";
    cin >> seleccion;
    while (!regex_match(seleccion, patron1)) {
        cout << "Error, entrada invalida: ";
        cin >> seleccion;
    }

    if (seleccion == "4") {
        return 0;
    } else if (seleccion == "1") {
        string escenario;
        regex patron2(R"([1-9]|[1][0-9])");
        cout << "Cual mapa desea cargar?: ";
        cin >> escenario;
        while (!regex_match(escenario, patron2)) {
            cout << "Error, entrada invalida: ";
            cin >> escenario;
        }
        tablero1.llenarTablero(archivoEscenarios, stoi(seleccion));
        tablero1.desplegar();
        //cambiar posicion de fichas
    } else if (seleccion == "2") {
        cout << "Fichas disponibles" << endl;
        fichas.desplegar();
    } else if (seleccion == "3") {
        cout << "Fichas disponibles" << endl;
        fichas.desplegar();
    }
    return 0;
}
#endif //CONTROL1_1_MENU_H