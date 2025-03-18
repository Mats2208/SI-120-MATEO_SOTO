#include <iostream>
#include "Vector.h"

using namespace std;
template <typename T> class MathVector : public Vector<T> {
    public:
    void CalcularPromedio(MathVector<T>* numeros) {
        cout << "Contenido del array" << endl;
        numeros->print();
        float contador = 0.0;
        float promedio = 0.0;
        for (int i = 0; i < numeros->getSize(); i++) {
            contador += numeros->at(i);
        }
        promedio = contador / numeros->getSize();
        cout << "EL promedio de este array es de: " << promedio << endl;
    }

    void CalcularMediana(MathVector<T>* numeros) {
        MathVector<T> DatosNoAgrupados;
        DatosNoAgrupados = *numeros;
        Sort(&DatosNoAgrupados);
        bool flag = false;
        int MiddleIndex = 0;
        if (DatosNoAgrupados.getSize() % 2 == 0) {
            cout << "Tienes un Array Par" << endl;
            flag = true;
        } else {
            cout << "Tienes un Array Impar" << endl;
            flag = false;
        }

        switch (flag) {
            case true: {
                MiddleIndex = (DatosNoAgrupados.getSize() / 2) -1;
                cout << "Middle Index: " << MiddleIndex << endl;
                cout << "Tu mediana va ser: " << DatosNoAgrupados.at(MiddleIndex) << " - " << DatosNoAgrupados.at(MiddleIndex + 1) << endl;
                float Mediana = (DatosNoAgrupados.at(MiddleIndex+1) + DatosNoAgrupados.at(MiddleIndex)) / 2.0;
                cout << "Mediana: " << Mediana<< endl;
            }
            case false: {
                MiddleIndex = (DatosNoAgrupados.getSize() / 2);
                cout << "Middle Index: " << MiddleIndex << endl;
                cout << "Mediana: " << DatosNoAgrupados.at(MiddleIndex)<< endl;
            }
            Default: cout << "No se encontro el Array" << endl;
        }
    }

    void Sort(Vector<T>* numeros) {
        cout << "Contenido del array Sin Sort" << endl;
        numeros->print();
        for (int i = 0; i < numeros->getSize(); i++) {
            for (int j = 0; j < numeros->getSize() - 1; j++) {
                if (numeros->at(i) < numeros->at(j)) {
                    T temp = numeros->at(j);
                    numeros->set(j,numeros->at(i));
                    numeros->set(i, temp);
                }
            }
        }
        cout <<"Contenido del array Con Sort" << endl;
        numeros->print();
    }
};


int main(){
    MathVector<int> v1;
    // for (int i = 0; i < 10; i++) {
    //     v1.pushBack(i);
    // }
    v1.pushBack(5);
    v1.pushBack(2);
    v1.pushBack(1);
    v1.pushBack(3);
    v1.pushBack(4);
    v1.pushBack(8);
    v1.pushBack(1000);
    cout << "===================" << endl;
    v1.CalcularPromedio(&v1);
    cout << "===================" << endl;
    v1.CalcularMediana(&v1);
    cout << "===================" << endl;

    return 0;
}