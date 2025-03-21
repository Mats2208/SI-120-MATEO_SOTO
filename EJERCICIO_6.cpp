#include <iostream>
#include "Vector.h"

using namespace std;

class Productos{
  private:
    int id;
    string nombre;
    float precio;
    int stock;
    public:
      Productos(int _id = 000, float _precio = 0.00, int _stock = 0, string _nombre = "Desconocido"){
        SetNombre(_nombre);
        SetId(_id);
        SetPrecio(_precio);
        SetStock(_stock);
      }
      void SetNombre(string _nombre){
        nombre = _nombre;
      }

      string GetNombre(){
        return nombre;
      }
      void SetId(int _id){
        if(id < 0){
          id = 0;
        } else {
          id = _id;
        }
      }

      void SetPrecio(float _precio){
        if(_precio < 0){
          precio = 0;
        } else {
          precio = _precio;
        }
      }

      void SetStock(int _stock){
        if(_stock < 0){
          stock = 0;
        } else {
           _stock = _stock;
        }
      }

      int GetId(){
        return id;
      }

      float GetPrecio(){
        return precio;
      }

      int GetStock(){
        return stock;
      }
};

class Inventario {
private:
  Vector<Productos> productos;
public:
  void agregarProducto(const Productos& product) {
    productos.pushBack(product);
  }

  void EliminarProducto(int id) {
    for (int i = 0; i < productos.getSize(); i++) {
      if (productos.at(i).GetId() == id) {
        productos.set(i, 0);
        cout << "Producto con ID = " << id << " eliminado." << endl;
        return;
      }
    }
    cout << "Producto con ID = " << id << " no encontrado." << endl;
  }

  void MostrarInventario() {
    productos.print();
  }
};

int main() {
  Inventario inventario;

  inventario.agregarProducto(Productos(1, 100.0, 10, "Lápiz"));
  inventario.agregarProducto(Productos(2, 200.0, 5, "Cuaderno"));
  inventario.agregarProducto(Productos(3, 300.0, 20, "Borrador"));

  inventario.MostrarInventario();

  inventario.EliminarProducto(2);

  inventario.MostrarInventario();

  return 0;
}