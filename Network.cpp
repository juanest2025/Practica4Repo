#include "Network.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
//agregar router
void Network::agregarRouter(const string& nombre) {
    if (!enlaces.count(nombre)) {
        enlaces[nombre] = {};
    }
}

//agregar enlace entre routers
void Network::agregarEnlace(const string& a, const string& b, int costo) {
    agregarRouter(a);
    agregarRouter(b);
    enlaces[a][b] = costo;
    enlaces[b][a] = costo; // Enlace bidireccional
}

//eliminar router
void Network::eliminarRouter(const string& nombre) {
    enlaces.erase(nombre);
    for (auto& [r, vecinos] : enlaces)
        vecinos.erase(nombre);
}

//mostrar red
void Network::mostrar() {
    cout << "\n--- Red actual ---\n";
    for (auto& [r, vecinos] : enlaces) {
        cout << "Router " << r << " -> ";
        for (auto& [v, costo] : vecinos)
            cout << v << "(" << costo << ") ";
        cout << endl;
    }
}

//calcula camino más corto (Dijkstra)
void Network::caminoMasCorto(const string& origen) {
    if (!enlaces.count(origen)) {
        cout << "El router no existe.\n";
        return;
    }

    map<string, int> dist;
    map<string, string> previo;
    vector<string> routers;

    for (auto& [r, _] : enlaces) {
        dist[r] = INT_MAX;
        routers.push_back(r);
    }
    dist[origen] = 0;

    while (!routers.empty()) {
        auto minIt = min_element(routers.begin(), routers.end(), [&](string a, string b) {
            return dist[a] < dist[b];
        });

        string actual = *minIt;
        routers.erase(minIt);

        for (auto& [vecino, costo] : enlaces[actual]) {
            if (dist[actual] != INT_MAX && dist[actual] + costo < dist[vecino]) {
                dist[vecino] = dist[actual] + costo;
                previo[vecino] = actual;
            }
        }
    }

    cout << "\n--- Caminos desde " << origen << " ---\n";
    for (auto& [destino, d] : dist) {
        if (destino == origen) continue;
        cout << "A " << destino << ": ";
        if (d == INT_MAX) {
            cout << "sin conexión.\n";
            continue;
        }
        cout << "costo " << d << " | camino: ";
        vector<string> ruta;
        string actual = destino;
        while (actual != origen && previo.count(actual)) {
            ruta.push_back(actual);
            actual = previo[actual];
        }
        ruta.push_back(origen);
        reverse(ruta.begin(), ruta.end());
        for (string r : ruta) cout << r << " ";
        cout << endl;
    }
}

//cargar desde un .txt
void Network::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    string a, b;
    int costo;
    int contador = 0;

    while (archivo >> a >> b >> costo) {
        agregarEnlace(a, b, costo);
        contador++;
    }

    archivo.close();
    cout << "Se cargaron " << contador << " enlaces desde el archivo.\n";
}

//crear red aleatoria
void Network::crearRedAleatoria(int cantidadRouters, int conexionesPorRouter) {
    enlaces.clear();
    srand(time(nullptr));

    //crear nombres: A, B...
    vector<string> nombres;
    for (int i = 0; i < cantidadRouters; i++) {
        string nombre = string(1, 'A' + i);
        agregarRouter(nombre);
        nombres.push_back(nombre);
    }

    //crear conexiones aleatorias
    for (int i = 0; i < cantidadRouters; i++) {
        for (int j = 0; j < conexionesPorRouter; j++) {
            string a = nombres[i];
            string b = nombres[rand() % cantidadRouters];
            if (a != b) {
                int costo = 1 + rand() % 10;
                agregarEnlace(a, b, costo);
            }
        }
    }

    cout << "Red aleatoria creada con " << cantidadRouters << " routers.\n";
}
