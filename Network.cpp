#include "Network.h"

void Network::agregarRouter(const string &nombre) {
    if (!enlaces.count(nombre)) enlaces[nombre] = {};
}

void Network::eliminarRouter(const string &nombre) {
    enlaces.erase(nombre);
    for (auto &p : enlaces)
        p.second.erase(nombre);
    tablas.erase(nombre);
}

void Network::agregarEnlace(const string &a, const string &b, int costo) {
    agregarRouter(a);
    agregarRouter(b);
    enlaces[a][b] = costo;
    enlaces[b][a] = costo;
}

void Network::eliminarEnlace(const string &a, const string &b) {
    if (enlaces.count(a)) enlaces[a].erase(b);
    if (enlaces.count(b)) enlaces[b].erase(a);
}

void Network::mostrarGrafo() const {
    cout << "Topología actual de la red:\n";
    for (auto &r : enlaces) {
        cout << r.first << ": ";
        bool first = true;
        for (auto &v : r.second) {
            if (!first) cout << ", ";
            cout << v.first << "(" << v.second << ")";
            first = false;
        }
        cout << "\n";
    }
}

void Network::mostrarVecinos(const string &router) const {
    if (!enlaces.count(router)) {
        cout << "El router '" << router << "' no existe.\n";
        return;
    }
    cout << "Vecinos de " << router << ":\n";
    for (auto &v : enlaces.at(router))
        cout << "  " << v.first << " (costo=" << v.second << ")\n";
}

void Network::inicializarTablas() {
    tablas.clear();
    for (auto &r : enlaces) {
        string router = r.first;
        for (auto &d : enlaces) {
            string destino = d.first;
            if (router == destino)
                tablas[router][destino] = {0, router};
            else if (enlaces[router].count(destino))
                tablas[router][destino] = {enlaces[router][destino], destino};
            else
                tablas[router][destino] = {INT_MAX / 4, "-"};
        }
    }
}

void Network::intercambiarVectores() {
    bool actualizado = true;
    while (actualizado) {
        actualizado = false;
        for (auto &r : enlaces) {
            string router = r.first;
            for (auto &vecino : enlaces[router]) {
                string v = vecino.first;
                int costoDirecto = vecino.second;
                for (auto &destino : tablas[v]) {
                    string d = destino.first;
                    int costo_v = destino.second.first;
                    if (costo_v == INT_MAX / 4) continue;
                    int nuevoCosto = costoDirecto + costo_v;
                    if (nuevoCosto < tablas[router][d].first) {
                        tablas[router][d] = {nuevoCosto, v};
                        actualizado = true;
                    }
                }
            }
        }
    }
}

void Network::mostrarTabla(const string &router) const {
    if (!tablas.count(router)) {
        cout << "El router '" << router << "' no existe o no tiene tabla.\n";
        return;
    }
    cout << "Tabla de enrutamiento para " << router << ":\n";
    cout << "Destino | Costo | Siguiente salto\n";
    cout << "--------------------------------\n";
    for (auto &p : tablas.at(router)) {
        string destino = p.first;
        int costo = p.second.first;
        string next = p.second.second;
        if (costo >= INT_MAX / 4)
            cout << destino << " | inalcanzable\n";
        else
            cout << destino << " | " << costo << " | " << (next == router ? "-" : next) << "\n";
    }
}

void Network::crearEjemploPequeño() {
    agregarEnlace("A", "B", 4);
    agregarEnlace("A", "D", 5);
    agregarEnlace("A", "C", 10);
    agregarEnlace("B", "C", 3);
    agregarEnlace("B", "D", 1);
    agregarEnlace("C", "D", 2);
    agregarEnlace("D", "E", 7);
}
