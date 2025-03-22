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

int main() {
  cout << "Prueba" << endl;

  return 0;
}