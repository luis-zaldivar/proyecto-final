#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

float saldo=0.0;

struct Libro{
	int clave;
	string nombre;
	string autor;
	int ao;
	float precio;
	int librosdisp;
	int ventas;
};

struct Cola{
	Libro libro;
	Cola *pntr;
};

void insertar(Cola *&, Cola *&, Cola *&);
void saldolibreria();
bool ver_colva(Cola *);
void registro(Cola *&);
void compra(Cola &, Cola&);

Cola *buscarlibro(Cola *&inicio, int clave){
	Cola *aux=inicio;
	while(aux!=NULL and aux->libro.clave!=clave){
		aux=aux->pntr;
	}
	return aux;
}

int main(){
	setlocale(LC_ALL, "");
	Cola *inicio=NULL;
	Cola *fin=NULL;
	Cola *nodo=NULL;
	Cola *libcompra=NULL;
	
	int opc,clav;
	
	do{
		cout<<"\t\t..::Libreria BuenAventura::..\n";
		cout<<"\t\t\t..::Bienvenido::..\n";
		cout<<"\t\t1- Dar de Altas Libros \n";
		cout<<"\t\t2- Libros Disponibles \n";
		cout<<"\t\t3- Compras\n";
		cout<<"\t\t4- Datos De Compras\n";
		cout<<"\t\t5- Saldo\n";
		cout<<"\t\t6- Salir \n";
		cin>>opc;
		switch(opc){
			case 1:
				nodo=new Cola();
				nodo->pntr=NULL;
				nodo->libro.librosdisp=0;
				cout<<"Ingrese la Clave del Libro: "<<endl;
				cin>>nodo->libro.clave;
				cout<<"Inserte el nombre del Libro: \n";
				getline(cin,nodo->libro.nombre);
				getline(cin,nodo->libro.nombre);
				cout<<"Inserte Autor del Libro: \n";
				getline(cin,nodo->libro.autor);
				//getline(cin,nodo->libro.autor);
				cout<<"Ingrese Año del Libro: \n";
				cin>>nodo->libro.ao;
				cout<<"Inserte el Precio del Libro: \n";
				cin>>nodo->libro.precio;
				cout<<"Numero de Libros Disponibles: \n";
				cin>>nodo->libro.librosdisp;
				insertar(inicio,fin,nodo);
				system("pause");
				break;
			case 2:
				if(ver_colva(inicio)){
					cout<<"No existe Registro\n";
				}else{
					registro(inicio);	
				}
				system("pause");
				break;
			case 3:
				if(ver_colva(inicio)){
					cout<<"No hay Libros disponibles \n";
				}else{
					while(true){
						registro(inicio);
						cout<<"Ingrese la Clave del Libro: \n";
						cin>>clav;
						libcompra=buscarlibro(inicio,clav);
						if(libcompra==NULL){
							cout<<"Ingrese la Clave de Nuevo: \n";
							continue;
						}else{
							if(libcompra->libro.librosdisp==0){
								cout<<"Cantidad de libros no Disponibles\n";
								continue;
							}else{
								cout<<"Venta de Libro Exitoso \n";
								libcompra->libro.librosdisp-=1;
								libcompra->libro.ventas+=1;
								system("Pause");
							}
						}
					}
				}break;
			case 4:
				cout<<"Datos de la Compra: \n";
				if(inicio==NULL){
					cout<<"No hay Compras Realizadas\n";
				}else{
					cout<<"\t Libro "<<inicio->libro.nombre<<" Vendido\n";
					compra(inicio,fin);
				}system("pause");
				break;
			case 5:
				saldolibreria();
				system("pause");
				break;
			case 6:
				cout<<" Hasta Luego...";
				cout<<endl;
				system("pause");
				break;
		}
		system("cls");
	}while(opc!=6);
}

void insertar(Cola *&inicio, Cola *&fin, Cola *&dato){
    if(ver_colva(inicio)){
	 	    inicio = dato;
        fin=dato;
	 }else{
        fin->pntr=dato;
        fin=fin->pntr;
	 }
	 if(inicio->pntr==NULL && inicio!=fin){
        inicio->pntr=fin;
	 }
}

void registro(Cola *&inicio){
	Cola *aux=inicio;
	while(aux!=NULL){
		cout<<"   "<<aux->libro.clave<<endl;
		cout<<"   "<<aux->libro.nombre<<endl;
		cout<<"   "<<aux->libro.autor<<endl;
		cout<<"   "<<aux->libro.ao<<endl;
		cout<<"El precio del Libro es: \n"<<aux->libro.precio<<endl;
		cout<<"Libros existentes: \n"<<aux->libro.librosdisp<<endl;
		aux=aux->pntr;
	}
}

void compra(Cola *&inicio, Cola *&fin){
	Cola *aux=inicio;
	if(inicio==fin){
		inicio=NULL;
		fin=NULL;
	}else{
		inicio=inicio->pntr;
	}
	saldo+=(aux->libro.precio)*(aux->libro.ventas);
	delete aux;
}
void saldolibreria(){
	cout<<"Los fondos obtenidos son: "<<saldo<<endl;
}

bool ver_colva(Cola *inicio){
	if(inicio==NULL){
		return true;
	}
	else{
		return false;
	}
}
