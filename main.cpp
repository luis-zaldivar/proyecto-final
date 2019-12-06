#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct NODO{
    string pedido;
    NODO*siguiente;
}; NODO* cola=NULL;



void agregar(string);
void eliminar();
string visualizar();

int main(){
	int opcion, rep=1;
	string orden, ped;
	while (rep==1){
      cout<<"\t\t ...::MENU::...\n 1.-Inserter pedido \n 2.-Mostrar pedido \n 3.-Elimnar\n 4.-salir\n";
      cin>>opcion;
      switch(opcion){
          case 1:
              cout<<"Introduzca el nombre del pedido: "; 
              getline(cin,orden); ///PARA LIMPIAR EL BUFFER
              getline(cin,orden); ///Lee una linea con espacios
              agregar(orden);
              break;
        case 2:
            ped=visualizar();
            if(ped!="No hay pedidos ")
                cout<<"El primer pedido  es: "<<ped;
            else
                cout<<"La lista de pedidos esta vacio"<<endl;
            break;
          case 3:
            cout<<"Se esta eliminando la el primer pedido de la cola "<<endl;
            eliminar();
            break;
        default:
            cout<<"Desea repetir el proceso? SI=1/NO=0 "; cin>>rep;
      }
  }
	
	
	return 0;
}
void agregar(string orden){
    if (cola==NULL){
        cola=new NODO();
        cola->pedido=orden;
        cola->siguiente=NULL;
    }else{
        NODO *aux=cola;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=new NODO();
        aux=aux->siguiente;
        aux->pedido=orden;
        aux->siguiente=NULL;
    }
}

void eliminar(){
    if (cola==NULL) return;
    NODO* aux=cola;
    cola=cola->siguiente;
    delete aux;
}

string visualizar(){
    if (cola!=NULL){
        return cola->pedido;
    }
    return "No hay pedidos  ";
}
