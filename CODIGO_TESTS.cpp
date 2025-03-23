#include <iostream>
#include "Vector.h"

int main() {
    Vector<Vector<int>> productos;
    for (int i = 0; i < productos.getSize(); i++) {
        for (int j = 0; j < productos.at(i).getSize(); j++) {
            productos.at(i).pushBack(j);
        }
    }

    for (int i = 0; i < productos.getSize(); i++) {
        for (int j = 0; j < productos.at(i).getSize(); j++) {
            productos.at(i).print();
        }
    }
}