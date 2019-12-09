#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct NODO{//estrucrura del producto
    string pedido;
    NODO*siguiente;
    
}; 
NODO* cola=NULL;


NODO *buscar(NODO *&lista,string producto){
	NODO *aux=lista;
	while(aux!=NULL and aux->pedido!=producto){
		aux=aux->siguiente;
	}
	if (aux==NULL){
		cout<<"el producto ya se entrego\n";
	}
	else{
		cout<<"el producto esta en camino\n";
	}
}


struct NODO1{//estructura de la direccion
    string direccion;
    NODO1*siguiente;
}; 
NODO1* cola1=NULL;
struct NODO2{//estructura del numero telefonico
    string dato;
    NODO2*siguiente;
};
NODO2* cola2=NULL;
struct lista{
	string pedidolis;
	lista *sigiente;
};

void insertarListaped( NODO *&, string);
void insertarListadir( NODO1 *&, string);
void insertarListatel( NODO2 *&, string);

void eliminarpedido(NODO *&,NODO1 *&,NODO2 *&, string);
void eliminardir(NODO1 *&, string);
void eliminartel(NODO2 *&, string);

void mostrarLista(NODO *,NODO1 *,NODO2 *);
void mostrar(NODO *&pedi,NODO1 *&dire,NODO2 *&tele){
	NODO *aux=pedi;
	NODO1 *aux1=dire;
	NODO2 *aux2=tele;
	while(aux!=NULL){
		cout<<"el pedido "<<aux->pedido;
		aux=aux->siguiente;
		if(aux != NULL){
			cout<<" con destino "<<aux1->direccion;
			aux1 = aux1 -> siguiente;
			if(aux2 != NULL){
				cout<<" y numero de referncia "<<aux2->dato<<endl;
				aux2 = aux2->siguiente;
			}
		}
		
	}
}

void buscarLista(NODO *, string);
void buscar(NODO &,NODO&);

void agregar(string);
void agregardir(string);
void agregartel(string );

void eliminar();
void eliminardir();
void eliminartel();

string visualizar();
string visualizardir();
string visualizartel();




NODO *lista = NULL;
NODO1 *lista1 = NULL;
NODO2 *lista2 = NULL;



int main(){
	int opcion, rep=1;
	string orden, ped,dir,add,num,bus;
	while (rep==1){
      cout<<"\t\t ...::MENU::...\n 1.-Inserter pedido \n 2.-Mostrar pedido \n 3.-Buscar\n 4.-Eliminar\n5.-salir\n";
      cin>>opcion;
      switch(opcion){
          case 1:
              cout<<"Introduzca el nombre del pedido: "; 
              getline(cin,orden); ///PARA LIMPIAR EL BUFFER
              getline(cin,orden); ///Lee una linea con espacios
              agregar(orden);
              insertarListaped(lista,orden);
              cout<<"Introduzca la direccion: ";
              getline(cin,dir); ///Lee una linea con espacios
              agregardir(dir);
              insertarListadir(lista1,dir);
              cout<<"Introduzca algun numero de telefono: "; 
              getline(cin,add); ///Lee una linea con espacios
              agregartel(add);
              insertarListatel(lista2,add);
              break;
        case 2:
        	cout<<"La lista de pedidos es \n";
        	mostrarLista(lista,lista1,lista2);
        	cout<<"\nen forma de cola es \n";
        	mostrar(cola,cola1,cola2);
            break;
        case 3:
        	cout<<"Cual es el producto que desea buscar: ";
        		getline(cin,orden);
				getline(cin,orden);
				buscar(lista,orden);
				break;
        	
        	break;
        case 4:
          	cout<<"Deme el producto que ya a sido entregado: ";
			getline(cin,orden);
			getline(cin,orden);
			eliminarpedido(lista,lista1,lista2,orden);/*
          	
            eliminar();
            eliminardir();
            eliminartel();
            cout<<"Se esta eliminando el primer pedido de la cola "<<endl;*/
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
    return "No hay direccion  ";
}
string visualizartel(){
    if (cola2!=NULL){
        return cola2->dato;
    }
    return "No hay numero telefonico ";
}


void insertarListaped(NODO *&lista,string transito){
	NODO *nuevo_nodo = new NODO();
	nuevo_nodo->pedido=transito;
	NODO *aux1=lista;
	NODO *aux2;
	while((aux1 != NULL) && (aux1 -> pedido < transito)){
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2 -> siguiente = nuevo_nodo;
	}
	nuevo_nodo -> siguiente = aux1;
}
void insertarListadir(NODO1 *&lista1,string dire){
	NODO1 *nuevo_nodo = new NODO1();
	nuevo_nodo->direccion=dire;
	NODO1 *aux1=lista1;
	NODO1 *aux2;
	while((aux1 != NULL) && (aux1 -> direccion < dire)){
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	
	if(lista1 == aux1){
		lista1 = nuevo_nodo;
	}
	else{
		aux2 -> siguiente = nuevo_nodo;
	}
	nuevo_nodo -> siguiente = aux1;
}
void insertarListatel(NODO2 *&lista2,string telefo){
	NODO2 *nuevo_nodo = new NODO2();
	nuevo_nodo->dato=telefo;
	NODO2 *aux1=lista2;
	NODO2 *aux2;
	while((aux1 != NULL) && (aux1 -> dato < telefo)){
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	
	if(lista2 == aux1){
		lista2 = nuevo_nodo;
	}
	else{
		aux2 -> siguiente = nuevo_nodo;
	}
	nuevo_nodo -> siguiente = aux1;
}


void mostrarLista(NODO *lista,NODO1 *lista1,NODO2 *lista2){
	NODO *actual = new NODO();
	NODO1 *actual1 = new NODO1();
	NODO2 *actual2 = new NODO2();
	actual = lista;
	actual1 = lista1;
	actual2 = lista2;
	
	while(actual != NULL){
		cout<<"El pedido "<<actual -> pedido;
		actual = actual -> siguiente;
		if(actual1 != NULL){
			cout<<" con destino "<<actual1->direccion;
			actual1 = actual1 -> siguiente;
			if(actual2 != NULL){
				cout<<" y numero de referncia "<<actual2->dato<<endl;
				actual2 = actual2->siguiente;
			}
		}
		//mostrarListadir(lista1);
	}
}
	

void eliminarpedido(NODO *&lista,NODO1 *&lista1,NODO2 *&lista2, string n){
	//Preguntar si la lista no esta vacia
	if(lista != NULL){
		NODO *aux_borrar;
		NODO *anterior = NULL;

    NODO1 *aux_borrar1;
		NODO1 *anterior1 = NULL;

    NODO2 *aux_borrar2;
		NODO2 *anterior2 = NULL;
		
		aux_borrar = lista;
    aux_borrar1=lista1;
    aux_borrar2=lista2;
		
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar -> pedido != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente;

      anterior1 = aux_borrar1;
			aux_borrar1 = aux_borrar1 -> siguiente;

      anterior2 = aux_borrar2;
			aux_borrar2 = aux_borrar2 -> siguiente;
		}
		
		//El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"El pedido no ha sido encontrado";
		}
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL){
			lista = lista -> siguiente;
			delete aux_borrar;
		}

		//El elemento esta en la lista pero no es el primer nodo
		else{
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
		}

    if(anterior1 == NULL){
			lista1 = lista1 -> siguiente;
			delete aux_borrar1;
		}else{
			anterior1 -> siguiente = aux_borrar1 -> siguiente;
			delete aux_borrar1;
		}

    if(anterior2 == NULL){
			lista2 = lista2 -> siguiente;
			delete aux_borrar2;
		}else{
			anterior2 -> siguiente = aux_borrar2 -> siguiente;
			delete aux_borrar2;
		}
	}
}
void eliminardir(NODO1 *&lista1, string n){
	//Preguntar si la lista no esta vacia
	if(lista1 != NULL){
		NODO1 *aux_borrar;
		NODO1 *anterior = NULL;
		
		aux_borrar = lista1;
		
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar -> direccion != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar = aux_borrar -> siguiente;
		}
		
		//El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL){
			lista = lista -> siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero no es el primer nodo
		else{
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
		}
	}
}
void eliminartel(NODO2 *&lista2, string n){
	//Preguntar si la lista no esta vacia
	if(lista2 != NULL){
		NODO2 *aux_borrar;
		NODO2 *anterior = NULL;
		
		aux_borrar = lista2;
		
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar -> dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar = aux_borrar -> siguiente;
		}
		
		//El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL){
			lista = lista -> siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero no es el primer nodo
		else{
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
		}
	}
}

void buscarLista(NODO *lista, string n){
	bool band = false;
	
	NODO *actual = new NODO();
	actual = lista;
	
	while((actual != NULL) && (actual -> pedido <= n)){
		if(actual -> pedido == n){
			band = true;
		}
		actual = actual -> siguiente;
	}
	
	if(band == true){
		cout<<"El producto "<<n<<" si se ha encontrado esta en envio\n";
	}
	else{
		cout<<"El producto "<<n<<" ya a sido entregado\n";
	}
}




