# Practica 4 Informatica 2 Simulación de una red de enrutadores

## Descripción general
Este proyecto simula el funcionamiento básico de una **red de routers (enrutadores)**.  
Cada router puede conectarse con otros mediante enlaces que tienen un **costo** (por ejemplo, distancia o tiempo).  
El programa permite calcular el **camino más corto** entre dos routers usando el **algoritmo de Dijkstra**, mostrando además las tablas de enrutamiento y los vecinos de cada nodo.

El objetivo es aplicar **Programación Orientada a Objetos (POO)** y el uso de **contenedores de la STL** (`map`, `vector`, `priority_queue`, etc.) para modelar una red.

---

## Funcionalidades principales
1. Agregar o eliminar routers y enlaces entre ellos.  
2. Visualizar la topología actual de la red (quién está conectado con quién).  
3. Mostrar los vecinos de un router y el costo de cada conexión.  
4. Calcular el camino más corto entre dos routers con su costo total.  
5. Ver la tabla de enrutamiento de cualquier router.  
6. Crear una red de ejemplo automáticamente para pruebas rápidas.  

---

## Lo que muestra en terminal
| Comando | Descripción |
|----------|-------------|
| `grafo` | Muestra toda la red con sus enlaces y costos. |
| `vecinos X` | Muestra los routers directamente conectados a `X`. |
| `camino A B` | Calcula y muestra el camino más corto entre `A` y `B`. |
| `tabla X` | Muestra la tabla de enrutamiento del router `X`. |
| `enlazar A B costo` | Agrega un nuevo enlace entre `A` y `B` con el costo indicado. |
| `salir` | Termina la ejecución del programa. |

---

## Estructura del la practica 
```
├── Network.h       # Declaración de la clase Network
├── Network.cpp     # Implementación de los métodos de Network
└── main.cpp        # Programa principal con pruebas y menú interactivo
```

---

## Ejemplo de salida
```
A: B(4), C(10), D(5)
B: A(4), C(3), D(1)
C: A(10), B(3), D(2)
D: A(5), B(1), C(2), E(7)
E: D(7)
Camino: A -> B -> C  | costo total=7
Tabla de enrutamiento de A:
Destino | Costo | Siguiente salto
--------------------------------
A | 0 | -
B | 4 | B
C | 7 | B
D | 5 | D
E | 12 | D
```
---

