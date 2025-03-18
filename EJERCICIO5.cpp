/*
Operaciones entre Vectores: Crea la clase VectorCalculator que tenga métodos
que reciban dos vectores como parámetros y calcule las siguientes operaciones
elemento a elemento: - - -
Suma
Resta
Multiplicac
 */
#include "Vector.h"
#include <iostream>

using namespace std;

template <typename T> class VectorCalculator : public Vector<T> {
  public:
    void Suma(Vector<T>* Vector1, Vector<T>* Vector2) {
      Vector1->print();
      Vector2->print();
    }
};

int main(){
  VectorCalculator<int> v1;
  VectorCalculator<int> v2;

  for (int i = 0; i < 10; i++) {
    v1.pushBack(i);
    v2.pushBack(i);
  }
  v1.Suma(&v1,&v2);
}