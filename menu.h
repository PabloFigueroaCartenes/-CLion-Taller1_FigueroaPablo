//
// Created by amnesia on 06-10-24.
//

#ifndef CONTROL1_1_MENU_H
#define CONTROL1_1_MENU_H
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int tipoDeClase(string tipo) {
    //valor 0 indica casilla bloqueada
    if ("Espadachin" == tipo) {
        return 1;
    } else if  ("Mago" == tipo) {
        return 2;
    } else if ("Tanque" == tipo) {
        return 3;
    } else if ("Arquero" == tipo) {
        return 4;
    }
    return -1;
}

vector<string> cortarCadena(const string& cadena, char coma) {
    vector<string> resultado;
    stringstream ss(cadena);
    string aux;
    while (getline(ss, aux, coma)) {
        resultado.push_back(aux);
    }
    return resultado;
}
void menu() {

}


#endif //CONTROL1_1_MENU_H