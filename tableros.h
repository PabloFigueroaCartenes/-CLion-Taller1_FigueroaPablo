#ifndef CONTROL1_1_TABLEROS_H
#define CONTROL1_1_TABLEROS_H

#include "fichas.h"

class MPP {
private:
    int filas, cols;
    Nodo* cabeza;

public:
    MPP() {
        filas = 4;
        cols = 3;
        cabeza = nullptr;
    }

    void insertar(int f, int c, int val) {
        if (val == 0 || val > 4) return;

        Nodo* NuevoNodo = new Nodo();
        NuevoNodo->fila = f;
        NuevoNodo->col = c;
        NuevoNodo->valor = val;
        NuevoNodo->siguiente = nullptr;

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

    void desplegar() {
        Nodo* aux = cabeza;
        cout << "Nodos en la MPP:" << endl;
        while (aux != nullptr) {
            cout << "(" << aux->fila << ", " << aux->col << ", " << aux->valor << ")" << endl;
            aux = aux->siguiente;
        }
    }
    void llenarTablero(string archivo, int escenario) {
        ifstream file(archivo);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo!!" << endl;
        }
        string linea;
        int pos = 0;
        while (file >> linea) {
            if (linea == "Ficha,Fila,Columna" ) {
                continue;
            } else if (linea == "Escenario" + to_string(escenario) ) {
                pos = 1;
                continue;
            } else if (linea == "Escenario" + to_string(escenario+1)) {
                break;
            } else if (pos == 1) {
                vector<string> entradas = cortarCadena(linea, ',');
                this->insertar(stoi(entradas.at(2)),stoi(entradas.at(1)), tipoDeClase(entradas.at(0)));
            }
        }
        file.close();
    }
    int getValue(int f, int c) {
        Nodo* aux = cabeza;
        while (aux != nullptr) {
            if (aux->fila == f && aux->col == c) {
                return aux->valor;
            }
            aux = aux->siguiente;
        }
        return 0;
    }

    ~MPP() {
        Nodo* aux;
        while (cabeza != nullptr) {
            aux = cabeza;
            cabeza = cabeza->siguiente;
            delete aux;
        }
    }
};
#endif //CONTROL1_1_TABLEROS_H