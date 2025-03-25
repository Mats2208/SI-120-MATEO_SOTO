# Practico de Vectores y Matrices

Este repositorio contiene la solución al práctico de vectores y matrices utilizando Programación Orientada a Objetos (POO). Los ejercicios están divididos en dos partes: vectores y matrices, y todos los ejercicios están implementados usando las clases `Vector<T>` y `Matrix<T, ROWS, COLS>`, las cuales fueron vistas en clase.

## Estructura del Proyecto

El proyecto está dividido en las siguientes partes:

### A) Vectores

1. **Simetría en un Vector**  
   Se implementa una función que verifica si un vector de enteros es simétrico.  
   Ejemplo de entrada: `[1, 2, 3, 2, 1]` → Es simétrico.  
   Ejemplo de entrada: `[1, 2, 3, 4]` → No es simétrico.

2. **Suma de Pares en Vectores**  
   Función que calcula la suma de los números pares en un vector de enteros.

3. **Cálculos Estadísticos sobre Vectores**  
   La clase `MathVector`, que hereda de `Vector<int>`, implementa métodos para calcular:
   - Promedio de los valores del vector.
   - Mediana del conjunto de datos.
   - Moda (el número que más veces aparece).

4. **Máximo y Mínimo**  
   La clase `MathVector` incluye métodos para encontrar:
   - El valor máximo del vector.
   - El valor mínimo del vector.

5. **Operaciones entre Vectores**  
   La clase `VectorCalculator` permite realizar operaciones entre dos vectores, como:
   - Suma
   - Resta
   - Multiplicación

6. **Inventario de Productos**  
   La clase `Inventario` gestiona un vector de objetos de la clase `Producto` y permite:
   - Agregar y eliminar productos.
   - Buscar productos por nombre.
   - Ordenar el inventario por precio.

7. **Seguimiento del Rendimiento Académico**  
   La clase `GestionAcademica` administra un vector de objetos `Estudiante` y permite:
   - Calcular el promedio de calificaciones de cada estudiante.
   - Obtener el promedio general del grupo de estudiantes.

### B) Matrices

1. **Suma de Elementos Impares en una Matriz**  
   Función que recibe una matriz de enteros y devuelve la suma de los números impares.

2. **Cálculo de la Suma de Cada Fila**  
   Función que recibe una matriz de enteros y devuelve un vector con la suma de cada fila.

3. **Simetría en una Matriz**  
   La clase `MathMatrix`, que hereda de `Matrix<int, ROWS, COLS>`, implementa un método que determina si una matriz cuadrada es simétrica.

4. **Máximo, Mínimo y Promedio en una Matriz**  
   La clase `MathMatrix` incluye métodos para encontrar:
   - El valor máximo.
   - El valor mínimo.
   - El promedio de la matriz.

5. **Operaciones entre Matrices**  
   La clase `MatrixCalculator` permite realizar operaciones entre matrices del mismo tamaño:
   - Suma
   - Resta
   - Multiplicación

6. **Almacén de Productos**  
   La clase `Almacen` gestiona una matriz de objetos `Producto` y permite:
   - Agregar un producto en una posición específica de la matriz.
   - Calcular el total de productos en una categoría (suma de las cantidades en una fila).

7. **Registro de Calificaciones**  
   La clase `GestionCalificaciones` administra una matriz de calificaciones donde las filas representan estudiantes y las columnas representan materias o evaluaciones. Permite:
   - Calcular el promedio de cada estudiante.
   - Obtener el promedio general del curso.

## Instrucciones para Ejecutar el Proyecto

1. Clona el repositorio:

    ```bash
    git clone [https://github.com/Mats2208/SI-120-MATEO_SOTO.git]
    ```

2. Asegúrate de tener configurado tu entorno de desarrollo con el compilador adecuado para C++.

3. Compila y ejecuta el código para cada uno de los ejercicios. Asegúrate de que las clases `Vector.h` y `Matriz.h` estén correctamente implementadas y que todos los métodos de las clases estén bien definidos.

