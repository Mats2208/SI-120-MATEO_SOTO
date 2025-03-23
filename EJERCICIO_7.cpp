#include <iostream>
#include "Vector.h"
#include <string>
#include <vector>
using namespace std;

class Estudiante {
private:
    int registro;
    string nombre;
    Vector<float> calificaciones;

public:
    Estudiante(int _registro = 0, string nombre = "", Vector<float> _calificaciones = 0) {
        SetRegistro(_registro);
        SetNombre(nombre);
    }

    void SetRegistro(int _registro) {
        if (_registro > 0) {
            registro = _registro;
        } else {
            registro = 0;
        }
    }

    int GetRegistro() {
        return registro;
    }

    void SetNombre(string _nombre) {
        nombre = _nombre;
    }

    string GetNombre() {
        return nombre;
    }

    void SetCalificaciones(float _calificacion) {
        if (_calificacion >= 0 && _calificacion <= 100) {
            calificaciones.pushBack(_calificacion);
        } else {
            calificaciones.pushBack(0);
        }
    }

    void SetArrayCalificaciones(Vector<float>* _calificaciones) {
        for (int i = 0; i < _calificaciones->getSize(); i++) {
            calificaciones.pushBack(_calificaciones->at(i));
        }
    }

    Vector<float>* GetArrayCalificaciones() {
        return &calificaciones;
    }

    void MostrarCalificaciones() {
        cout << "Registro: " << GetRegistro() << endl;
        cout << "Nombre: " << GetNombre() << endl;
        cout << "Calificaciones: " << endl;
        for (int i = 0; i < calificaciones.getSize(); i++) {
            cout << calificaciones.at(i) <<" ";
        }
        cout << endl;
    }
};

class GestionAcademica {
    private:
    Vector<Estudiante> estudiantes;
    public:

    void AgregarEstudiantes(Estudiante* estu) {
        Estudiante aux;
        aux.SetRegistro(estu->GetRegistro());
        aux.SetNombre(estu->GetNombre());
        aux.SetArrayCalificaciones(estu->GetArrayCalificaciones());
        estudiantes.pushBack(aux);
    }

    void MostrarEstudiantes() {
        for (int i = 0; i < estudiantes.getSize(); i++) {
            estudiantes.at(i).MostrarCalificaciones();
        }
    }
};
int main() {
    Estudiante estudiante(2024111556, "Mateo");
    estudiante.SetCalificaciones(100);
    estudiante.SetCalificaciones(80);
    estudiante.SetCalificaciones(50);
    estudiante.SetCalificaciones(85);
    estudiante.SetCalificaciones(70);
    Estudiante estudiante_2(2024112170, "MAB");
    estudiante_2.SetCalificaciones(100);
    estudiante_2.SetCalificaciones(80);
    estudiante_2.SetCalificaciones(50);
    estudiante_2.SetCalificaciones(85);
    estudiante_2.SetCalificaciones(70);

    GestionAcademica Admin;

    Admin.AgregarEstudiantes(&estudiante);
    Admin.AgregarEstudiantes(&estudiante_2);

    Admin.MostrarEstudiantes();
    return 0;
}