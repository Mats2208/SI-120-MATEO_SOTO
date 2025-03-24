#include <iostream>
#include "Vector.h"
#include <string>

using namespace std;

class Productos{
  private:
    int id;
    string nombre;
    float precio;
    int stock;
    public:
      Productos(int _id = 0, float _precio = 0.00, int _stock = 0, string _nombre = "Desconocido"){
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
        if(_id <= 0){
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
           stock = _stock;
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

      void print() {
        cout << "ID: " << GetId() << ", Nombre: " << GetNombre() << ", Precio: " << GetPrecio() << ", Stock: " << GetStock() << endl;
      }
};

class inventario {
private:
  Vector<Productos> productos;
public:
  void AgregarProductos(Productos producto) {
    productos.pushBack(producto);
  }

  void EliminarProducto(int id) {
    for (int i = 0; i < productos.getSize(); i++) {
      if (productos.at(i).GetId() == id) {
        productos.removeAt(i); // La aplique en el Vector.h porque sale mas facil el manejo de los items y resize junto a otras cosas que desde aqui
        break;
      }
    }
  }

  Productos BusquedaPorNombre(string nombre) {
    for (int i = 0; i < productos.getSize(); i++) {
      if (productos.at(i).GetNombre() == nombre) {
        return productos.at(i);
      }
    }
  }

  void MostrarProductos() { //Meramente funcional en la terminal
    for (int i = 0; i < productos.getSize(); i++) {
      productos.at(i).print();
    }
  }

  void SortByPrice() {
    Vector<Productos> aux;
    for (int i = 0; i < productos.getSize(); i++) {
      aux.pushBack(productos.at(i));
    }

    for (int i = 0; i < aux.getSize() - 1; i++) {
      for (int j = 0; j < aux.getSize() - i - 1; j++) {
        if (aux.at(j).GetPrecio() > aux.at(j + 1).GetPrecio()) {
          Productos temp = aux.at(j);
          aux.set(j, aux.at(j + 1));
          aux.set(j + 1, temp);
        }
      }
    }
    for (int i = 0; i < aux.getSize(); i++) {
      productos.set(i, aux.at(i));
    }
  }
};

int main() {
  cout << "Creacion del producto" << endl;
  Productos P1(150, 25, 5, "shampoo");
  Productos P2(50, 12, 3, "Escoba");
  Productos P3(40, 15, 10, "Rastrillo");
  Productos P4(60, 25, 10, "Trapo");
  Productos P5(80, 100, 10, "Desengrasante");
  Productos P6(10, 150, 10, "Lavavajilla");
  inventario chest;
  chest.AgregarProductos(P1);
  chest.AgregarProductos(P2);
  chest.AgregarProductos(P3);
  chest.AgregarProductos(P4);
  chest.AgregarProductos(P5);
  chest.AgregarProductos(P6);


  cout << "Inventario actual" << endl;
  chest.MostrarProductos();


  cout << "========================" << endl;
  chest.EliminarProducto(150);


  cout << "Usando la funcion eliminar" << endl;
  chest.MostrarProductos();
  cout << "========================" << endl;


  cout << "Busqueda por nombre" << endl;
  chest.BusquedaPorNombre("Rastrillo").print(); //Lo hago funcion de PRODUCTOS porque puede llegar a ser mas util, y solo uso .print() para que salga en consola


  cout << "Invetario ordenado por precio de menor a mayor "<< endl;
  chest.SortByPrice(); // Ahora devuelve un inventario'
  chest.MostrarProductos();
  return 0;
}