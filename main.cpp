#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct NODO{
    string pedido;
    NODO*siguiente;
}; NODO* cola=NULL;
struct NODO1{
    string direccion;
    NODO1*siguiente;
}; NODO1* cola1=NULL;
struct NODO2{
    string dato;
    NODO2*siguiente;
}; NODO2*cola2=NULL;


void agregar(string);
void agregardir(string);
void agregartel(string );
void eliminar();
void eliminardir();
void eliminartel();
string visualizar();
string visualizardir();
string visualizartel();

int main(){
	int opcion, rep=1;
	string orden, ped,dir,add,num;
	while (rep==1){
      cout<<"\t\t ...::MENU::...\n 1.-Inserter pedido \n 2.-Mostrar pedido \n 3.-Elimnar\n 4.-salir\n";
      cin>>opcion;
      switch(opcion){
          case 1:
              cout<<"Introduzca el nombre del pedido: "; 
              getline(cin,orden); ///PARA LIMPIAR EL BUFFER
              getline(cin,orden); ///Lee una linea con espacios
              agregar(orden);
              cout<<"Introduzca la direccion: "; 
              getline(cin,dir); ///Lee una linea con espacios
              agregardir(dir);
              cout<<"Introduzca algun numero de telefono: "; 
              getline(cin,add); ///Lee una linea con espacios
              agregartel(add);
              break;
        case 2:
        	dir=visualizardir();
            ped=visualizar();
            num=visualizartel();
            if(ped!="No hay pedidos "){
                cout<<"El primer pedido  es: "<<ped<<endl;
                cout<<"La direccion es: "<<dir<<endl;
                cout<<"El numero relefonico es: "<<num<<endl;
            }
            else
                cout<<"La lista de pedidos esta vacio"<<endl;
            break;
          case 3:
            cout<<"Se esta eliminando la el primer pedido de la cola "<<endl;
            eliminar();
            eliminardir();
            eliminartel();
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
void agregardir(string dir){
    if (cola1==NULL){
        cola1=new NODO1();
        cola1->direccion=dir;
        cola1->siguiente=NULL;
    }else{
        NODO1 *aux=cola1;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=new NODO1();
        aux=aux->siguiente;
        aux->direccion=dir;
        aux->siguiente=NULL;
    }
}
void agregartel(string add){
    if (cola2==NULL){
        cola2=new NODO2();
        cola2->dato=add;
        cola2->siguiente=NULL;
    }else{
        NODO2 *aux=cola2;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=new NODO2();
        aux=aux->siguiente;
        aux->dato=add;
        aux->siguiente=NULL;
    }
}

void eliminar(){
    if (cola==NULL) return;
    NODO* aux=cola;
    cola=cola->siguiente;
    delete aux;
}
void eliminardir(){
    if (cola1==NULL) return;
    NODO1* aux=cola1;
    cola1=cola1->siguiente;
    delete aux;
}
void eliminartel(){
    if (cola2==NULL) return;
    NODO2*aux=cola2;
    cola2=cola2->siguiente;
    delete aux;
}

string visualizar(){
    if (cola!=NULL){
        return cola->pedido;
    }
    return "No hay pedidos  ";
}
string visualizardir(){
    if (cola1!=NULL){
        return cola1->direccion;
    }
    return "No hay pedidos  ";
}
string visualizartel(){
    if (cola2!=NULL){
        return cola2->dato;
    }
    return "No hay pedidos  ";
}



