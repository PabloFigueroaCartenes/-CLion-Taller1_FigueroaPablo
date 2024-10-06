//
// Created on 26-09-24.
//

#include "menu.h"

#ifndef CONTROL1_1_FICHAS_H
#define CONTROL1_1_FICHAS_H

struct Nodo {
    int fila;
    int col;
    int valor;
    int salud;
    int atk;
    int def;
    int rango;
    Nodo* siguiente;
};

class ficha {
private:
    Nodo* cabeza;
public:
    ficha() {
        cabeza = nullptr;
    }

    void llenarFichas(string archivo) {
        ifstream file(archivo);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo!!" << endl;
        }
        string linea;
        while (file >> linea) {
	        Nodo* NuevoNodo = new Nodo();
	        NuevoNodo->siguiente = nullptr;

            vector<string> entradas = cortarCadena(linea, ',');
            NuevoNodo->valor = tipoDeClase(entradas.at(0));
            NuevoNodo->salud = stoi(entradas.at(1));
            NuevoNodo->atk = stoi(entradas.at(2));
            NuevoNodo->def = stoi(entradas.at(3));
            NuevoNodo->rango = stoi(entradas.at(4));

	        if (cabeza == nullptr) {
        	    cabeza = NuevoNodo;
	        } else {
        	    Nodo* aux = cabeza;
	            while (aux->siguiente != nullptr) {
        	        aux = aux->siguiente;
	            }
        	    aux->siguiente = NuevoNodo;
	            }
	        }
        file.close();
    }
    void desplegar() {
        Nodo* aux = cabeza;
        cout << "fichas:" << endl;
        while (aux != nullptr) {
            cout << "(" << aux->valor << ", ";
            cout << aux->salud << ", ";
            cout << aux->atk << ", ";
            cout << aux->def << ", ";
            cout << aux->rango << ")" << endl;
            aux = aux->siguiente;
        }
    }
    ~ficha() {
        Nodo* aux;
        while (cabeza != nullptr) {
            aux = cabeza;
            cabeza = cabeza->siguiente;
            delete aux;
        }
    }
};

#endif //CONTROL1_1_FICHAS_H
