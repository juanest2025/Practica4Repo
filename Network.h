#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Network {
private:
    //estructura es router -> (vecino -> costo directo)
    map<string, map<string, int>> enlaces;

    //tabla de enrutamiento router -> (destino -> (costo, siguiente salto))
    map<string, map<string, pair<int, string>>> tablas;

public:
    void agregarRouter(const string &nombre);
    void eliminarRouter(const string &nombre);
    void agregarEnlace(const string &a, const string &b, int costo);
    void eliminarEnlace(const string &a, const string &b);
    void mostrarGrafo() const;
    void mostrarVecinos(const string &router) const;
    void inicializarTablas();
    void intercambiarVectores(); //simula la comunicación entre routers
    void mostrarTabla(const string &router) const;
    void crearEjemploPequeño();
};

#endif
