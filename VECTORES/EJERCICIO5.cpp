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
    void Suma(VectorCalculator<T>* Vector1, VectorCalculator<T>* Vector2) {
      VectorCalculator<T> VectorResuelto;
      if (Vector1->getSize() >= Vector2->getSize()) {
        for (int i = 0; i < Vector1->getSize(); i++) {
          VectorResuelto.pushBack(Vector1->at(i));
        }
        for (int i = 0; i < Vector2->getSize(); i++) {
          VectorResuelto.set(i, (Vector1->at(i) + Vector2->at(i)));
        }
      } else {

        for (int i = 0; i < Vector2->getSize(); i++) {
          VectorResuelto.pushBack(Vector1->at(i));
        }
        for (int i = 0; i < Vector1->getSize(); i++) {
          VectorResuelto.set(i, (Vector1->at(i) + Vector2->at(i)));
        }
      }
      cout << "Array de Suma N1" << endl;
      Vector1->print();
      cout << "Array de Suma N2" << endl;
      Vector2->print();
      cout << "Array Resultante" << endl;
      VectorResuelto.print();
    }

    void Resta(VectorCalculator<T>* Vector1, VectorCalculator<T>* Vector2) {
        VectorCalculator<T> VectorResuelto;
        if (Vector1->getSize() >= Vector2->getSize()) {
          for (int i = 0; i < Vector1->getSize(); i++) {
            VectorResuelto.pushBack(Vector1->at(i));
          }
          for (int i = 0; i < Vector2->getSize(); i++) {
            VectorResuelto.set(i, (Vector1->at(i) - Vector2->at(i)));
          }
        } else {

          for (int i = 0; i < Vector2->getSize(); i++) {
            VectorResuelto.pushBack(Vector1->at(i));
          }
          for (int i = 0; i < Vector1->getSize(); i++) {
            VectorResuelto.set(i, (Vector1->at(i) - Vector2->at(i)));
          }
        }
        cout << "Array de Resta N1" << endl;
        Vector1->print();
        cout << "Array de Resta N2" << endl;
        Vector2->print();
        cout << "Array Resultante" << endl;
        VectorResuelto.print();
      }

    void Multiplicacion(VectorCalculator<T>* Vector1, VectorCalculator<T>* Vector2) {
        VectorCalculator<T> VectorResuelto;
        float Suma = 0.0;
        if (Vector1->getSize() >= Vector2->getSize()) {
          for (int i = 0; i < Vector1->getSize(); i++) {
            VectorResuelto.pushBack(Vector1->at(i));
          }
          for (int i = 0; i < Vector2->getSize(); i++) {
            VectorResuelto.set(i, (Vector1->at(i) * Vector2->at(i)));
            Suma += VectorResuelto.at(i);
          }

        } else {

          for (int i = 0; i < Vector2->getSize(); i++) {
            VectorResuelto.pushBack(Vector1->at(i));
          }
          for (int i = 0; i < Vector1->getSize(); i++) {
            VectorResuelto.set(i, (Vector1->at(i) - Vector2->at(i)));
            Suma += VectorResuelto.at(i);
          }
        }
        cout << "Array de Multiplicacion N1" << endl;
        Vector1->print();
        cout << "Array de Multiplicacion N2" << endl;
        Vector2->print();
        cout << "Suma Resultante" << endl;
        cout << Suma << endl;
      }
};

int main(){
  VectorCalculator<int> v1;
  VectorCalculator<int> v2;
  VectorCalculator<int> v3;

  // for (int i = 0; i < 10; i++) {
  //   v1.pushBack(i);
  //   v2.pushBack(i);
  // }

  for (int i = 0; i <= 10; i ++) {
    v1.pushBack(i);
  }

  for (int i = 0; i <= 10; i ++) {
    v2.pushBack(i+1);
  }

  cout << "==============================================" << endl;
  v1.Suma(&v2, &v1);
  cout << "==============================================" << endl;
  v1.Resta(&v2, &v1);
  cout << "==============================================" << endl;
  v1.Multiplicacion(&v2, &v1);
}