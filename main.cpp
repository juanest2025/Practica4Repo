#include "Network.h"

int main() {
    Network red;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n----MENÚ PRINCIPAL----\n";
        cout << "1. Agregar router\n";
        cout << "2. Agregar enlace\n";
        cout << "3. Eliminar router\n";
        cout << "4. Mostrar red\n";
        cout << "5. Calcular caminos desde un router\n";
        cout << "6. Cargar red desde archivo\n";
        cout << "7. Crear red aleatoria\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string r;
            cout << "Nombre del router: ";
            cin >> r;
            red.agregarRouter(r);
        }
        else if (opcion == 2) {
            string a, b;
            int c;
            cout << "Router origen: "; cin >> a;
            cout << "Router destino: "; cin >> b;
            cout << "Costo del enlace: "; cin >> c;
            red.agregarEnlace(a, b, c);
        }
        else if (opcion == 3) {
            string r;
            cout << "Router a eliminar: "; cin >> r;
            red.eliminarRouter(r);
        }
        else if (opcion == 4) {
            red.mostrar();
        }
        else if (opcion == 5) {
            string origen;
            cout << "Router origen: "; cin >> origen;
            red.caminoMasCorto(origen);
        }
        else if (opcion == 6) {
            string archivo;
            cout << "Nombre del archivo (ej: red.txt): ";
            cin >> archivo;
            red.cargarDesdeArchivo(archivo);
        }
        else if (opcion == 7) {
            int n, c;
            cout << "Cantidad de routers: ";
            cin >> n;
            cout << "Conexiones por router: ";
            cin >> c;
            red.crearRedAleatoria(n, c);
        }
        else if (opcion == 0) {
            cout << "Saliendo...\n";
        }
        else {
            cout << "Opción no válida.\n";
        }
    }

    return 0;
}
