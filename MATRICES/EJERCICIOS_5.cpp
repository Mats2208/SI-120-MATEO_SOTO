#include <iostream>
#include "Matriz.h"
#include <stdexcept>


using namespace std;
template<typename T, int ROWS, int COLS>
class MatrixCalculator {
    public:
    Matrix<T, ROWS, COLS> SumaDeVectores(Matrix<int, ROWS, COLS> mat, Matrix<T, ROWS, COLS> mat2) {
        if (mat.numCols() != mat2.numCols()) {
            throw invalid_argument("Las matrices tienen tamanos invalidos");
        } else {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    mat.set(i, j, mat.at(i, j) + mat2.at(i, j));
                }
            }
            return mat;
        }
    }

    Matrix<T, ROWS, COLS> RestaDeVectores(Matrix<int, ROWS, COLS> mat, Matrix<T, ROWS, COLS> mat2) {
        if (mat.numCols() != mat2.numCols()) {
            throw invalid_argument("Las matrices tienen tamanos invalidos");
        } else {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    mat.set(i, j, mat.at(i, j) - mat2.at(i, j));
                }
            }
            return mat;
        }
    }

    Matrix<T, ROWS, COLS> MultiplicacionDeVectores(const Matrix<T, ROWS, COLS>& mat, const Matrix<T, ROWS, COLS>& mat2) {
        Matrix<T, ROWS, COLS> resultado;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                T suma = T();
                for (int k = 0; k < COLS; k++) {
                    suma += mat.at(i, k) * mat2.at(k, j);
                }
                resultado.set(i, j, suma);
            }
        }
        return resultado;
    }
};
int main(){
    Matrix<int, 3, 3> m;
    Matrix<int, 3, 3> m2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m.set(i,j,i);
            m2.set(i,j,i+10);
        }
    }
    cout << "Matrices: " << endl;
    m.print();
    m2.print();

    MatrixCalculator<int, 3, 3> Resultado;
    cout << "La suma de dos matrices DE IGUAL TAMANO es: " << endl;
    Resultado.SumaDeVectores(m, m2).print();

    cout << "La resta de dos matrices DE IGUAL TAMANO es: " << endl;
    Resultado.RestaDeVectores(m, m2).print();

    cout << "La matriz resultante de la multiplicacion de matrices cuadradas es:" << endl;
    Resultado.MultiplicacionDeVectores(m, m2).print();

    return 0;
}