//
// Created on 26-09-24.
//
#include <iostream>

using namespace std;
#ifndef CONTROL1_1_FICHAS_H
#define CONTROL1_1_FICHAS_H

struct Node {
    int fila;
    int col;
    int valor;
    int salud;
    int atk;
    int def;
    int rango;
    Node* siguiente;
};

#endif //CONTROL1_1_FICHAS_H