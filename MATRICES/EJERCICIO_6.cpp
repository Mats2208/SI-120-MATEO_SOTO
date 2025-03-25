#include <iostream>
#include "matriz.h"

using namespace std;

class Producto {
private:
  int id;
  string nombre;
  double precio;
  int stock;
  public:
  Producto(int _id = 0, string _nombre = "Desconocido", double _precio = 0, int _stock = 0) {
    SetID(_id);
    SetNombre(_nombre);
    SetPrecio(_precio);
    SetStock(_stock);
  }

  void SetID(int _id) {
    if (_id > 0) {
      id = _id;
    } else {
      id = 0;
    }
  }

  int GetID() {
    return id;
  }

  void SetNombre(string _nombre) {
    nombre = _nombre;
  }

  string GetNombre() {
    return nombre;
  }

  void SetPrecio(double _precio) {
    if (_precio > 0) {
      precio = _precio;
    } else {
      precio = 0;
    }
  }

  double GetPrecio() {
    return precio;
  }

  void SetStock(int _stock) {
    if (_stock > 0) {
      stock = _stock;
    } else {
      stock = 0;
    }
  }

  int GetStock() {
    return stock;
  }

  void MostrarProducto() {
    cout << "-----------------------" << endl;
    cout << "Id: " << GetID() << endl;
    cout << "Nombre: " << GetNombre() << endl;
    cout << "Precio: " << GetPrecio() << endl;
    cout << "Stock: " << GetStock() << endl;
    cout << "-----------------------" << endl;
  }
};

class almacen {
  private:
  Matrix<Producto, 3, 3> matriz;
  public:
  almacen() {}

  void AgregarProducto(int fila, int columna, const Producto valor) {
    matriz.set(fila, columna, valor);
  }

  void MostrarProducto(Producto Producto) {
    Producto.MostrarProducto();
  }

  int CalcularTotalCategoria(int fila) {
    int total = 0;
    if (fila < 0 || fila >= matriz.numRows()){
      throw invalid_argument("No se encontra el fila");
    }
    for (int col = 0; col < matriz.numCols(); col++) {
      Producto producto = matriz.at(fila, col);
      total += producto.GetStock();
    }
    return total;
  }

};

int main(){
  Producto P1(150, "Prueba", 25, 10);
  almacen Almacen;
  Almacen.AgregarProducto(1, 0, P1);
  Almacen.MostrarProducto(P1);

  Producto P2(155, "Prueba2", 30, 25);
  Almacen.AgregarProducto(1, 1, P2);
  Almacen.MostrarProducto(P2);

  cout << "La cantidad de productos almacenados en la Fila 1 es: " << Almacen.CalcularTotalCategoria(1);
}