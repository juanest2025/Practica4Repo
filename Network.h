#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Network {
private:
    map<string, map<string, int>> enlaces; //router -> (vecino -> costo)

public:
    void agregarRouter(const string& nombre);
    void agregarEnlace(const string& a, const string& b, int costo);
    void eliminarRouter(const string& nombre);
    void mostrar();
    void caminoMasCorto(const string& origen);
    void cargarDesdeArchivo(const string& nombreArchivo);
    void crearRedAleatoria(int cantidadRouters, int conexionesPorRouter);

};

#endif
