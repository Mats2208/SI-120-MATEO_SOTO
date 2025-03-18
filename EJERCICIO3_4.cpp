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
        for (int i = 0; i < numeros->getSize(); i++) {
            DatosNoAgrupados.pushBack(numeros->at(i));
        }
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
            break;
            case false: {
                MiddleIndex = (DatosNoAgrupados.getSize() / 2);
                cout << "Middle Index: " << MiddleIndex << endl;
                cout << "Mediana: " << DatosNoAgrupados.at(MiddleIndex)<< endl;
            }
            break;
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

    void Moda(Vector<T>* numeros) {
        if (numeros->getSize() == 0) {
            cout << "El vector está vacío." << endl;
            return;
        }
        Vector<int> frecuencias;
        for (int i = 0; i < numeros->getSize(); i++) {
            int contador = 0;
            for (int j = 0; j < numeros->getSize(); j++) {
                if (numeros->at(i) == numeros->at(j)) {
                    contador++;
                }
            }
            frecuencias.pushBack(contador);
        }

        int maxFrecuencia = frecuencias.at(0);
        for (int i = 1; i < frecuencias.getSize(); i++) {
            if (frecuencias.at(i) > maxFrecuencia) {
                maxFrecuencia = frecuencias.at(i);
            }
        }

        cout << "Moda: ";
        for (int i = 0; i < numeros->getSize(); i++) {
            if (frecuencias.at(i) == maxFrecuencia) {
                bool yaImpreso = false;
                for (int k = 0; k < i; k++) {
                    if (numeros->at(i) == numeros->at(k)) {
                        yaImpreso = true;
                        break;
                    }
                }
                if (!yaImpreso) {
                    cout << numeros->at(i) << " ";
                }
            }
        }
        cout << "Frecuencia maxima: " << maxFrecuencia << endl;
    }

    void Max(Vector<T>* numeros) {
        cout << "Contenido del array Max" << endl;
        numeros->print();
        T max = numeros->at(0);
        for (int i = 1; i < numeros->getSize(); i++) {
            if (max > numeros->at(i)) {
                max = max;
            } else {
                max = numeros->at(i);
            }
        }

        cout << "El numero maximo es: " << max << endl;
    }

    void Min(Vector<T>* numeros) {
        cout << "Contenido del array Min" << endl;
        numeros->print();
        T min = numeros->at(0);
        for (int i = 1; i < numeros->getSize(); i++) {
            if (min < numeros->at(i)) {
                min = min;
            } else {
                min = numeros->at(i);
            }
        }

        cout << "El numero minimo es: " << min << endl;
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
    v1.pushBack(5);
    v1.pushBack(5);
    v1.pushBack(4);
    v1.pushBack(1);
    v1.pushBack(8);
    v1.pushBack(1);
    v1.pushBack(1000);
    cout << "===================" << endl;
    v1.CalcularPromedio(&v1);
    cout << "===================" << endl;
    v1.CalcularMediana(&v1);
    cout << "===================" << endl;
    v1.Moda(&v1);
    cout << "===================" << endl;
    v1.Max(&v1);
    v1.Min(&v1);
    return 0;
}