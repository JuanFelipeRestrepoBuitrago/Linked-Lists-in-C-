#include <iostream>
#include <string>
#include "LinkedList.h"
#include "thread"
using namespace std;

struct OptionException : public exception {
    const char * what() const noexcept override {
        return "Opcion no valida en el menu, intente de nuevo con valores entre 1 y 12";
    }
};

void menu(){
    cout << "Menu Lista enlazada de Enteros: \n1.Crear Lista \n2.Insertar Elemento al Inicio \n3.Insertar Elemento al Final \n4.Insertar Elemento en una Posicion \n5.Eliminar Elemento por Valor \n6.Eliminar Elemento por Posicion \n7.Buscar Elemento por Valor \n8.Buscar Elemento por Posicion \n9.Tamaño de la Lista \n10.Eliminar Lista \n11.Imprimir Lista \n12.Salir" << endl;
}

int main() {
    LinkedList list = LinkedList();
    int option;

    while(true){
        this_thread::sleep_for(chrono::milliseconds(2500));
        menu();
        try {
            cin >> option;
            if (cin.fail()){
                throw ios_base::failure("Input no valido");
            }
            if(option == 12){
                break;
            }else if(option < 1 || option > 12){
                throw OptionException();
            }
        }catch (OptionException & e){
            cin.clear();
            cin.ignore();
            cout << e.what() << endl;
            continue;
        }catch (ios_base::failure & e){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Error: Debe Ingresar un Numero Entero Menor de 11 Digitos" << endl;
            continue;
        }
        while (true){
            try {
                int data;
                switch (option) {
                    case 1:
                        cout << "Ingrese un Numero Entero: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.createLinkedList(data);
                        cout << "Lista Creada Exitosamente" << endl;
                        break;
                    case 2:
                        cout << "Ingrese Valor a Agregar: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.insertAtTheTop(data);
                        cout << "Elemento Insertado Exitosamente" << endl;
                        break;
                    case 3:
                        cout << "Ingrese Valor a Agregar: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.insertAtTheEnd(data);
                        cout << "Elemento Insertado Exitosamente" << endl;
                        break;
                    case 4:
                        cout << "Ingrese Valor a Agregar: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        cout << "Ingrese la Posicion en la que Quiere Agregar el Valor Ingresado: ";
                        int position;
                        cin >> position;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        if (list.insertAtTheIndex(data, position)) {
                            cout << "Elemento Insertado Exitosamente" << endl;
                        }
                        break;
                    case 5:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Eliminar");
                        }
                        cout << "Ingrese el Valor a Eliminar: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.deleteValue(list.getHead(), data);
                        cout << "Elemento Eliminado Exitosamente" << endl;

                        break;
                    case 6:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Eliminar");
                        }
                        cout << "Ingrese la Posicion del Elemento a Eliminar: ";
                        cin >> position;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.deleteIndex(position);
                        cout << "Elemento Eliminado Exitosamente" << endl;

                        break;
                    case 7:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Buscar");
                        }
                        cout << "Ingrese el Valor a Buscar: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        if (list.searchValue(data)) {
                            cout << "Elemento Encontrado en la Posicion: " << list.getIndex(data) << endl;
                        } else {
                            cout << "Elemento No Encontrado" << endl;
                        }

                        break;
                    case 8:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Buscar");
                        }
                        cout << "Ingrese la Posicion del Elemento a Buscar: ";
                        cin >> position;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        if (list.searchIndex(position)) {
                            cout << "Elemento Encontrado con Valor: "<< list.getData(position) << endl;
                        } else {
                            cout << "Elemento No Encontrado" << endl;
                        }

                        break;
                    case 9:
                        cout << "El Tamaño de la Lista es: " << list.getSize() << endl;
                        break;
                    case 10:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia");
                        }
                        list.deleteList(list.getHead());
                        cout << "Lista Eliminada Exitosamente" << endl;
                        break;
                    default:
                        list.printList(list.getHead());
                        break;
                }
            }catch (ios_base::failure & e){
                cin.clear();
                cin.ignore();
                cout << "Error: Debe Ingresar un Numero Entero Menor de 11 Digitos" << endl;
                continue;
            }catch (out_of_range & e){
                cout << e.what() << endl;
            }
            break;
        }

    }
    return 0;
}
