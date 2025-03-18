/*
Inventario de Productos: Crea la clase Inventario, que gestione un vector de
objetos de la clase Producto con los atributos:
- id (numerico)
- nombre
- precio
- cantidad en stock
El sistema debe permitir:
- Agregar y eliminar productos
- Buscar productos por nombre.
- Ordenar el inventario por precio
 */

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
  Vector<Productos> producto;

  public:
  void Invetario(Productos _producto) {
    producto.pushBack(_producto);
  }

  void EliminarProducto(int id) {
    for (int i = 0; i < producto.getSize(); i++) {
      if (producto.at(i).GetId() == id) {
        cout << "Se encontro el producto" << endl;
      }
    }
  }
};

int main(){
  Inventario invetario(132, 25, 2, "Mantequilla");

}