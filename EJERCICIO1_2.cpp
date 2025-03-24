#include <iostream>
#include "Vector.h"

using namespace std;

bool VerificarSimetria(Vector<int>* numeros) {
    Vector<int> inverso;
    for (int i = numeros->getSize() - 1; i >= 0; i--) {
        inverso.pushBack(numeros->at(i));
    }
    int contador = 0;
    for (int i = 0; i < numeros->getSize(); i++) {
        if (numeros->at(i) == inverso.at(i)) {
            contador += 1;
        } else {
            break;
        }
    }
    if (contador != numeros->getSize()) {
        return false;
    } else {
        return true;
    }
}

float SumaDePares(Vector<int>* numeros) {
    int suma = 0;
    for (int i = 0; i < numeros->getSize(); i++) {
        if (numeros->at(i) % 2 == 0) {
            suma += numeros->at(i);
        }
    }
    return suma;
}

int main() {
    Vector<int> numeros;
    for (int i = 0; i < 10; i++) {
        numeros.pushBack(1);
        numeros.pushBack(2);
    }
    cout << "El vector es simetrico? " << VerificarSimetria(&numeros) << endl;
    cout << "La suma de todos los numeros pares es: " << SumaDePares(&numeros);
    return 0;
}