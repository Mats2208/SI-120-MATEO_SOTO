#include <iostream>
#include "Matriz.h"
#include "Vector.h"

using namespace std;

template<int ROWS,  int COLUMS>
int SumaDeMatriz(const Matrix<int, ROWS, COLUMS> Matriz) { //Solo impares
  int suma = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMS; j++) {
      if (Matriz.at(i,j) % 2 != 0) {
        suma += Matriz.at(i, j);
      }
    }
  }
  return suma;
}

template<int ROWS,  int COLUMS>
Vector<int> SumaDeFilas(const Matrix<int, ROWS, COLUMS> Matriz) {
  Vector<int> resultado;
  for (int i = 0; i < ROWS; i++) {
    int suma = 0;
    for (int j = 0; j < COLUMS; j++) {
      suma += Matriz.at(i,j);
    }
    resultado.pushBack(suma);
  }
  return resultado;
}

int main(){
  Matrix<int, 3,3> mat;

  mat.set(0, 0, 1);
  mat.set(0, 1, 2);
  mat.set(0, 2, 3);
  mat.set(1, 0, 4);
  mat.set(1, 1, 5);
  mat.set(1, 2, 6);
  mat.set(2, 0, 7);
  mat.set(2, 1, 8);
  mat.set(2, 2, 9);
  mat.print();
  cout << "Suma de impares dentro de la matriz es: " << SumaDeMatriz(mat) << endl;
  cout << "La suma de los valores por cada fila es: ";
  SumaDeFilas(mat).print();
}