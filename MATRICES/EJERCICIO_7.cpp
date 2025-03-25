#include <iostream>
#include "Matriz.h"
#include "Vector.h"

using namespace std;

template<typename T, int ROWS, int COLS>
class GestionCalificaciones {
  private:
  Matrix<T, ROWS, COLS> notas;
  public:

  void AgregarEstudiante(int fila, int id) {
    if (fila >= ROWS) {
      cout << "Haz superado el tamano de la matriz" << endl;
    }
    notas.set(fila, 0, id);
  }

  void AgregarNotaEstudiante(int fila, int col, double nota) {
    if (fila < 0 || fila >= ROWS || col < 1 || col >= COLS) {
      cout << "Índices fuera de rango al agregar nota." << endl;
      return;
    }
    notas.set(fila, col, nota);
  }

  void MostrarNotas(int fila) {
    if (fila < 0 || fila >= ROWS) {
      cout << "Fila fuera de rango al mostrar notas." << endl;
      return;
    }
    cout << "ID del estudiante en fila " << fila << ": "
         << notas.at(fila, 0) << endl;
  }

  double PromedioEstudiante(int fila) {
    if (fila < 0 || fila >= ROWS) {
      cout << "Fila fuera de rango al calcular promedio de estudiante." << endl;
      return 0.0;
    }
    double suma = 0.0;
    for (int c = 1; c < COLS; c++) {
      suma += notas.at(fila, c);
    }
    return suma / (COLS - 1);
  }

  double PromedioGeneral() {
    double total = 0.0;
    int cantidadNotas = (ROWS) * (COLS - 1);

    for (int r = 0; r < ROWS; r++) {
      for (int c = 1; c < COLS; c++) {
        total += notas.at(r, c);
      }
    }
    return total / cantidadNotas;
  }
};

int main (){
  GestionCalificaciones<int, 3, 3> calificaciones;
  calificaciones.AgregarEstudiante(0,2024111556);
  calificaciones.AgregarNotaEstudiante(0, 1, 45);
  calificaciones.AgregarNotaEstudiante(0, 2, 58);
  calificaciones.MostrarNotas(0);


  calificaciones.AgregarEstudiante(1,2024112170);
  calificaciones.AgregarNotaEstudiante(1, 1, 58);
  calificaciones.AgregarNotaEstudiante(1, 2, 42);
  calificaciones.MostrarNotas(1);

  calificaciones.AgregarEstudiante(2,2024111558);
  calificaciones.AgregarNotaEstudiante(2, 1, 100);
  calificaciones.AgregarNotaEstudiante(2, 2, 35);
  calificaciones.MostrarNotas(2);

  for (int i = 0; i < 3; i++) {
    cout << "--------------------------------" << endl;
    calificaciones.MostrarNotas(i);
    cout << "Promedio Estudiante fila " << i << ": "
         << calificaciones.PromedioEstudiante(i) << endl;
    cout << "-------------------------------" << endl;
  }

  cout << "Promedio general del curso: "
     << calificaciones.PromedioGeneral() << endl;

  return 0;

}