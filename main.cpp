#include <iostream>
#include "LinkedList.h"
using namespace std;
struct OptionException : public exception {
    const char * what() const noexcept override {
        return "Opcion no valida en el menu, intente de nuevo con valores entre 1 y 11";
    }
};
void menu(){
    cout << "Menu Lista enlazada de Enteros: \n1.Crear Lista \n2.Insertar Elemento al Inicio \n3.Insertar Elemento al Final \n4.Insertar Elemento en una Posicion \n5.Eliminar Elemento por Valor \n6.Eliminar Elemento por Posicion \n7.Buscar Elemento por Valor \n8.Buscar Elemento por Posicion \n9.Tamaño de la Lista \n10.Imprimir Lista \n11.Salir \n" << endl;
}

int main() {
    LinkedList list = LinkedList();

    while(true){
        menu();
        int option = 0;
        try {
            cin >> option;
            if(option == 11){
                break;
            }
            if (option >= 1 && option <= 11) {
                throw OptionException();
            }
        }catch (OptionException & e){
            cin.clear();
            cout << e.what() << endl;
            continue;
        }

        switch (option) {
            case 1:
                int data;
                cout << "Ingrese el valor del nodo: ";
                cin >> data;
                list.createLinkedList(data);
                break;
            default:
                break;
        }

    }

    return 0;
}
