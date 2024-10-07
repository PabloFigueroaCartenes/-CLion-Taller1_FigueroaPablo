//
// Created on 26-09-24.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

using namespace std;


#ifndef CONTROL1_1_FICHAS_H
#define CONTROL1_1_FICHAS_H

int tipoDeClase(string tipo) {
    //valor 0 indica casilla bloqueada
    if ("Espadachin" == tipo || "espadachin" == tipo) {
        return 1;
    } else if  ("Mago" == tipo || "mago" == tipo) {
        return 2;
    } else if ("Tanque" == tipo || "tanque" == tipo) {
        return 3;
    } else if ("Arquero" == tipo || "arquero" == tipo) {
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
    Nodo* getFicha(int pos) {
        Nodo* aux = cabeza;
        for (int i = 0; i < pos; i++) {
            if (aux == nullptr) {
                cerr << "Error: fuera de limite" << endl;
                return nullptr;
            }
            aux = aux->siguiente;
        }
        return aux;
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
