#include <iostream>
#include "Vector.h"

using namespace std;
class MathVector : public Vector<int> {
    public:
    float CalcularPromedio(MathVector* numeros) {
        float contador = 0.0;
        float promedio = 0.0;
        for (int i = 0; i < numeros->getSize(); i++) {
            contador += numeros->at(i);
        }
        promedio = contador / numeros->getSize();
        return promedio;
    }

    float CalcularMediana(MathVector* numeros) {
        MathVector DatosNoAgrupados;
        float Mediana = 0;
        for (int i = 0; i < numeros->getSize(); i++) {
            DatosNoAgrupados.pushBack(numeros->at(i));
        }
        Sort(&DatosNoAgrupados);
        bool flag = false;
        int MiddleIndex = 0;
        if (DatosNoAgrupados.getSize() % 2 == 0) {
            flag = true;
        } else {
            flag = false;
        }

        switch (flag) {
            case true: {
                MiddleIndex = (DatosNoAgrupados.getSize() / 2) -1;
                Mediana = (DatosNoAgrupados.at(MiddleIndex+1) + DatosNoAgrupados.at(MiddleIndex)) / 2.0;
            }
            break;
            case false: {
                MiddleIndex = (DatosNoAgrupados.getSize() / 2);
                Mediana =DatosNoAgrupados.at(MiddleIndex);
            }
            break;
        }
        cout << endl;
        DatosNoAgrupados.print();
        return Mediana;
    }

    void Sort(Vector* numeros) {
        for (int i = 0; i < numeros->getSize(); i++) {
            for (int j = 0; j < numeros->getSize() - 1; j++) {
                if (numeros->at(i) < numeros->at(j)) {
                    int temp = numeros->at(j);
                    numeros->set(j,numeros->at(i));
                    numeros->set(i, temp);
                }
            }
        }
    }

    void Moda(MathVector* numeros) {
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

    int Max(Vector* numeros) {
        int max = numeros->at(0);
        for (int i = 1; i < numeros->getSize(); i++) {
            if (max > numeros->at(i)) {
                max = max;
            } else {
                max = numeros->at(i);
            }
        }
        return max;
    }

    int Min(Vector* numeros) {
        int min = numeros->at(0);
        for (int i = 1; i < numeros->getSize(); i++) {
            if (min < numeros->at(i)) {
                min = min;
            } else {
                min = numeros->at(i);
            }
        }
        return min;
    }

};


int main(){
    MathVector v1;
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
    cout << "El valor promedio de este array es: " << v1.CalcularPromedio(&v1) << endl;
    cout << "===================" << endl;
    cout << "La media de este valor es: " << v1.CalcularMediana(&v1) << endl;
    cout << "===================" << endl;
    cout << "La moda de este array es: " << endl; v1.Moda(&v1);
    cout << "===================" << endl;
    cout << "EL valor maximo de este array es: " << v1.Max(&v1) << endl ;
    cout << "El valor minimo de este array es: " << v1.Min(&v1) << endl;
    return 0;
}