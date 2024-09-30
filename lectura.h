//
// Created on 27-09-24.
//
#include <regex>
#include "tableros.h"

using namespace std;

int lectura(string archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo!!" << endl;
        return 1;
    }
    string linea;
    while (file >> linea) {
        cout << linea << endl;
    }
    file.close();
    return 0;
}

int parametrosYMatriz(string archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo!!" << endl;
        return -1;
    }
    string linea;
    int pos = 0;

    regex patron1(R"(Escenario[0-9])");
    regex patron2(R"(Escenario[0-9][0-9])");
    while (file >> linea) {
        if (regex_match(linea,patron1) || regex_match(linea,patron2) || linea == "Ficha,Fila,Columna" ) {
            continue;
        }
        pos += 1;
    }
    file.close();
    return pos;
}

int parametrosXMatriz(string archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo!!" << endl;
    }
    string linea;
    int pos = 0;
    while (file >> linea) {
        for(int i = 0 ; i < linea.length() ; i++) {
            if ( linea.at(i) == ',' ) {
                pos += 1;
                continue;
            }
        }
        if (pos == 0) { continue; } else { break; }
    }
    file.close();
    return pos+1;
}
#ifndef CONTROL1_1_LECTURA_H
#define CONTROL1_1_LECTURA_H

#endif //CONTROL1_1_LECTURA_H

