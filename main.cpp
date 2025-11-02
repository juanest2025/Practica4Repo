#include <iostream>
#include <string>
#include "Network.h"

using namespace std;

void ejecutarPruebas() {
    Network red;
    red.crearEjemploPequeño();
    red.mostrarGrafo();

    cout << "\nInicializando tablas de enrutamiento...\n";
    red.inicializarTablas();

    cout << "Intercambiando vectores de distancia...\n";
    red.intercambiarVectores();

    red.mostrarTabla("A");
    red.mostrarTabla("B");
    red.mostrarTabla("C");
    red.mostrarTabla("D");
    red.mostrarTabla("E");
}

int main() {
    cout << "----simulación de vector de distancia ----\n";
    ejecutarPruebas();

    Network red;
    red.crearEjemploPequeño();
    red.inicializarTablas();
    red.intercambiarVectores();

    cout << "\n---modo interactivo ---\n";
    cout << "Comandos: grafo, vecinos X, tabla X, enlazar A B costo, salir\n";

    string cmd;
    while (true) {
        cout << "> ";
        if (!(cin >> cmd)) break;
        if (cmd == "salir") break;
        else if (cmd == "grafo") red.mostrarGrafo();
        else if (cmd == "vecinos") {
            string x; cin >> x; red.mostrarVecinos(x);
        } else if (cmd == "tabla") {
            string x; cin >> x; red.mostrarTabla(x);
        } else if (cmd == "enlazar") {
            string a,b; int c; cin >> a >> b >> c;
            red.agregarEnlace(a,b,c);
            red.inicializarTablas();
            red.intercambiarVectores();
            cout << "Enlace agregado y tablas actualizadas.\n";
        } else cout << "Comando no reconocido.\n";
    }

    cout << "Programa finalizado.\n";
    return 0;
}

