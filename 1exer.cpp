#include <iostream>
#include "Vector.h"

using namespace std;

void VerificarSimetria(Vector<int>* numeros) {
    cout << "Array actual" << endl;
    numeros->print();
    Vector<int> inverso;
    for (int i = numeros->getSize() - 1; i >= 0; i--) {
        inverso.pushBack(numeros->at(i));
    }
    cout << "Array inverso" << endl;
    inverso.print();
    int contador = 0;
    for (int i = 0; i < numeros->getSize(); i++) {
        if (numeros->at(i) == inverso.at(i)) {
            cout <<"Posicion: "<< i << ". " << numeros->at(i) << " y " << inverso.at(i) << " son iguales" << endl;
            contador += 1;
        } else {
            cout << "El array no es simetrico a partir de: " << numeros->at(i) << endl;
            break;
        }
    }
    if (contador != numeros->getSize()) {
        cout << "El array no es simetrico" << endl;
    } else {
        cout << "El array es simetrico" << endl;
    }
}

void SumaDePares(Vector<int>* numeros) {
    cout << "Array actual" << endl;
    numeros->print();
    int suma = 0;
    for (int i = 0; i < numeros->getSize(); i++) {
        if (numeros->at(i) % 2 == 0) {
            suma += numeros->at(i);
        } else {
            cout << numeros -> at(i) << " en la posicion: " << i <<" no es par, y no se cuenta en la suma" << endl;
        }
    }
    cout << "La suma total de los numeros pares es: " << suma << endl;
}

int main() {
    Vector<int> numeros;
    for (int i = 0; i < 10; i++) {
        numeros.pushBack(1);
        numeros.pushBack(2);
    }
    VerificarSimetria(&numeros);
    SumaDePares(&numeros);
    return 0;
}