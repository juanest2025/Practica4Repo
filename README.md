# Práctica 4 – Informática 2  
## Simulación de una red de enrutadores

Esta practica simula el funcionamiento básico de una **red de routers (enrutadores)**, donde cada router puede conectarse con otros mediante enlaces que tienen un **costo** (como la distancia, el tiempo o la calidad del enlace).  

El programa calcula los **caminos más cortos** entre routers usando el **algoritmo de Dijkstra**, permitiendo modificar la topología de la red en tiempo real.  

El objetivo es aplicar los conceptos de **Programación Orientada a Objetos (POO)** y el uso de **contenedores de la STL** (`map`, `vector`, `pair`, `algorithm`, etc.) para modelar una red.

---

## Objetivos de la practica

- Modelar routers y conexiones utilizando POO.  
- Manipular estructuras dinámicas con los contenedores de la STL.  
- Implementar una simulación funcional de una red de enrutadores.  
- Permitir agregar, eliminar y conectar routers durante la ejecución.  
- Calcular el camino más corto entre routers y mostrarlo al usuario.

---

## Funcionalidades principales

1.  **Agregar o eliminar routers** en cualquier momento.  
2.  **Agregar enlaces** entre routers con un costo determinado.  
3.  **Visualizar la red completa**, mostrando las conexiones entre routers.  
4.  **Calcular los caminos más cortos** desde un router origen hacia todos los demás.  
5.  **Cargar una red desde un archivo `.txt`**, que describe la topología (routers y costos).  
6.  **Crear una red aleatoria**, indicando el número de routers y conexiones por cada uno.  
7.  Uso del **algoritmo de Dijkstra** para obtener rutas óptimas.  

---

##  Estructura del proyecto

```
├── Network.h # Declaración de la clase Network  
├── Network.cpp # Implementación de los métodos de Network  
├── main.cpp # Programa principal con menú interactivo  
└── red.txt # Carga de red desde el archivo 
```

## Uso del programa (menú principal)

Al ejecutar el programa, se mostrará un menú como este:

```
----MENÚ PRINCIPAL----

1. Agregar router
    
2. Agregar enlace
    
3. Eliminar router
    
4. Mostrar red
    
5. Calcular caminos desde un router
    
6. Cargar red desde archivo
    
7. Crear red aleatoria
    
8. Salir
```

### Ejemplo de uso

#### Cargar una red desde archivo

```
Seleccione una opción: 6  
Nombre del archivo (ej: red.txt): red.txt  
Se cargaron 6 enlaces desde el archivo.
```
#### Mostrar la red

```
--- Red actual ---  
Router A -> B(4) D(5) C(10)  
Router B -> A(4) C(3) D(1)  
Router C -> B(3) D(2) A(10)  
Router D -> A(5) C(2) B(1)
```

#### Calcular caminos desde A

```
--- Caminos desde A ---  
A B: costo 4 | camino: A B  
A C: costo 7 | camino: A B C  
A D: costo 5 | camino: A D
```


