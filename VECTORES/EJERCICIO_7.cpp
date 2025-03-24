#include <iostream>
#include "Vector.h"

using namespace std;

class Estudiante {
private:
    int registro;
    string nombre;
    Vector<double> v1;
    public:

    Estudiante(string _nombre = "Desconocido", int _registro = 0) {
        SetNombre(_nombre);
        SetRegistro(_registro);
    }

    void SetRegistro(int _registro) {
        if (_registro > 0) {
            registro = _registro;
        }
    }

    int GetRegistro() {
        return registro;
    }

    int GetIndex() {
        return v1.getSize();
    }
    void SetNombre(string _nombre) {
        nombre = _nombre;
    }

    string GetNombre() {
        return nombre;
    }

    void AgregarNotas(double notas) {
        v1.pushBack(notas);
    }

    double CalcularPromedio() {
        double promedio = 0, suma = 0;
        for (int i = 0; i < v1.getSize(); i++) {
            suma += v1.at(i);
        }
        promedio = suma / v1.getSize();
        return promedio;
    }
    void MostrarInformacion() {
        cout << "nombre: " << GetNombre()<< endl;
        cout << "registro: " << registro << endl;
        cout << "notas: ";
        v1.print();
    }

};

class GestionAcademica {
    private:
    Vector<Estudiante> Alumnos;
    public:
    void AgregarAlumnos( Estudiante a) {
        Alumnos.pushBack(a);
    }

    void MostrarAlumnos() {
        for (int i = 0; i < Alumnos.getSize();i++) {
            Alumnos.at(i).MostrarInformacion();
        }
    }

    double CalcularPromedioEstudiante(Estudiante* a) {
        return a->CalcularPromedio();
    }

    Vector<double> CalcularPromedioDeTodos() {
        Vector<double> promedio;
        for (int i = 0; i < Alumnos.getSize();i++) {
            promedio.pushBack(Alumnos.at(i).CalcularPromedio());
        }
        return promedio;
    }

    double PromedioGeneral() {
        double promedio = 0, suma = 0;
        for (int i = 0; i < Alumnos.getSize();i++) {
            suma += Alumnos.at(i).CalcularPromedio();
        }
        promedio = suma / Alumnos.getSize();
        return promedio;
    }
};
int main() {
    Estudiante alumno1("Mateo", 2024111556);
    alumno1.AgregarNotas(55);
    alumno1.AgregarNotas(70);
    alumno1.AgregarNotas(75);
    alumno1.AgregarNotas(36);

    Estudiante alumno2("Juan", 2024112170);
    alumno2.AgregarNotas(23);
    alumno2.AgregarNotas(57);
    alumno2.AgregarNotas(23);
    alumno2.AgregarNotas(47);

    GestionAcademica administracion;
    administracion.AgregarAlumnos(alumno1);
    administracion.AgregarAlumnos(alumno2);

    //Promedio de cada estudiante
    cout << "El promedio del estudiante N1 es: " <<administracion.CalcularPromedioEstudiante(&alumno1) << endl;
    cout << "El promedio del estudiante N2 es: " <<administracion.CalcularPromedioEstudiante(&alumno2) << endl;

    //Promedio de TODOS los estudiantes
    cout << "El promedio de todos los estudiantes almacenados en un vector es: " << endl;
    administracion.CalcularPromedioDeTodos().print();

    //Obtener Promedio General de la clase
    cout << "El promedio General de toda la clase es de: " << administracion.PromedioGeneral() << endl;


}