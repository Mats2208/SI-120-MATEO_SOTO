#include <iostream>
#include "Matriz.h"
#include "Vector.h"

using namespace std;

template<int ROWS, int COLS>
class MathMatrix : public Matrix<int, ROWS, COLS> {
public:
    MathMatrix() : Matrix<int, ROWS, COLS>() {}

    bool EsSimetrica(Matrix<int, ROWS, COLS> mat) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++){
                if(ROWS != COLS){
                  return false;
                } else {
                  for(int i = 0; i < ROWS; i++){
                    for(int j = 0; j < COLS; j++){
                      if(mat.at(i,j) != mat.at(j,i)){
                        return false;
                      }
                    }
                    return true;
                  }
                }
                return false;
            }

        }
    }

    int ValorMaximo(Matrix<int, ROWS, COLS> mat) {
      int valor_maximo = mat.at(0, 0);
      for (int i = 0; i < ROWS; i++) {
        for (int j = 1; j < COLS; j++) {
          if (mat.at(i,j) > valor_maximo) {
            valor_maximo = mat.at(i,j);
          }
        }
      }
      return valor_maximo;
    }

  int ValorMinimo(Matrix<int, ROWS, COLS> mat) {
      int valor_minimo = mat.at(0, 0);
      for (int i = 0; i < ROWS; i++) {
        for (int j = 1; j < COLS; j++) {
          if (mat.at(i,j) < valor_minimo) {
            valor_minimo = mat.at(i,j);
          }
        }
      }
      return valor_minimo;
    }

  double PromedioDeMatriz(Matrix<int, ROWS, COLS> mat) {
      double promedio = 0, suma = 0;
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          suma += mat.at(i,j);
        }
      }
      return promedio = suma / (ROWS * COLS);
    }
};

int main() {
  MathMatrix<3,3> m;

  m.set(0,0,7);
  m.set(0,1,2);
  m.set(0,2,3);
  m.set(1,0,2);
  m.set(2,0,3);
  m.set(1,1,9);
  m.set(2,1,5);
  m.set(1,2,5);
  m.set(2,2,6);
  m.print();

  cout <<"La matriz es simetrica? " << m.EsSimetrica(m) << endl; //Devuelve un bool
  //Se puede usar condicionar if para mostrar otro dato en consola
  //Pero para utilidad es mejor dejarlo en bool

  cout <<"El valor maximo de la Matriz es: " << m.ValorMaximo(m) << endl;

  cout <<"El valor minimo de la Matriz es: " << m.ValorMinimo(m) << endl;

  cout <<"El Promedio de la Matriz es: " << m.PromedioDeMatriz(m) << endl;

}