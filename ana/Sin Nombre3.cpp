#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
float total=0.0;

struct Autobus{ 
    float precio;
    int boletosDisponibles;
    int boletosComprados;
    string nombreAutobus;
};

struct Pasajero{
	string Nombre;
	string Fecha;
	string Tipo;
	string Origen;
	string Destino;	
	int Costo;
};

struct Nodo{
    Autobus a; 
    Pasajero p;
	Nodo *siguiente; 
};

bool colaVacia(Nodo *&frente){
    if(frente==NULL){ 
        return true;
    }else{ 
        return false;
    }
}

void mostrardt(Nodo *&frente, Nodo *&fin){ 
    Nodo *aux=frente;
    if(frente== fin){
      frente= NULL;
      fin=NULL;
    }
    else{ 
      frente = frente->siguiente;
    }
    total+=(aux->a.precio)*(aux->a.boletosComprados); 
    delete aux;
}


void mostrarAutobus(Nodo *&frente){ 
    Nodo *aux=frente; 
    while(aux!=NULL){
    	cout<<endl;
        cout<<"Nombre del Autobus: "<<aux->a.nombreAutobus<<endl;
        cout<<"El precio del boleto es: "<<aux->a.precio<<endl;
        cout<<"Boletos disponibles: "<<aux->a.boletosDisponibles<<endl;
        cout<<"Boletos Vendidos: "<<aux->a.boletosComprados<<endl;
        aux=aux->siguiente; 
        cout<<endl;
    }
}


void Agregar(Nodo *&frente,Nodo *&fin,Nodo *&nuevoNodo){ 
    if(colaVacia(frente)){
		frente = nuevoNodo;
        fin=nuevoNodo;
	 }else{
        fin->siguiente=nuevoNodo;
        fin=fin->siguiente;
	 }
	 if(frente->siguiente==NULL && frente!=fin){ 
        frente->siguiente=fin;
	 }
}

void ingresarPasajeros(Nodo *&frente,Nodo *&fin,Nodo *&nuevoNodo){ 
    if(colaVacia(frente)){
		frente = nuevoNodo;
        fin=nuevoNodo;
	 }else{
        fin->siguiente=nuevoNodo;
        fin=fin->siguiente;
	 }
	 if(frente->siguiente==NULL && frente!=fin){ 
        frente->siguiente=fin;
	 }
}

void mostrarTotal(){
    cout<<"El total es: "<<total<<endl;
}

Nodo* Buscarboleto(Nodo *&frente,string nombrep){
    Nodo *aux=frente;
    while(aux!=NULL and aux->a.nombreAutobus!=nombrep){ 
        aux=aux->siguiente; 
    }
    return aux;

}

int main(){
	Autobus a;
	Pasajero p;
	string nombreAutobus;
    int opc;
    char dato;
    string nombrep; 
    Nodo *frente=NULL;
    Nodo *fin=NULL;
    Nodo *nuevoNodo=NULL; 
    Nodo *boletoComprado=NULL; 
	Nodo *modificarPasajero=NULL;
    do{
    	cout<<"\n..::TERMINAL DE AUTOBUCES::.. \n";
    	cout<<"\n ELIJA UN NUMERO DEL MENU SIGUIENTE: \n";    
    	cout<<" 1- INGRESAR DATOS DE AUTOBUS "<<endl;
    	cout<<" 2- VER AUTOBUCES DISPONIBLES  "<<endl;
    	cout<<" 3- COMPRAR BOLETOS "<<endl;    
    	cout<<" 4- INGRESAR DATOS DEL PASAJERO"<<endl;
    	cout<<" 5- MOSTRAR DATOS DEL PASAJERO  "<<endl;
    	cout<<" 6- MODIFICAR DATOS DEL PASAJERO "<<endl;
    	cout<<" 7- MONTO TOTAL DE VENTA DE BOLETOS "<<endl;
    	cout<<" 8. SALIR"<<endl;
    	cout<<"OPCION: ";
        cin>> opc;
        switch(opc){
        case 1: ///AGREGAR DATOS DEL AUTOBUS
            nuevoNodo=new Nodo(); 
            nuevoNodo->siguiente=NULL; 
            nuevoNodo->a.boletosDisponibles=0; 
            cout<<"Ingrese el nombre del destino a donde va : ";
            getline(cin,nuevoNodo->a.nombreAutobus); 
            getline(cin,nuevoNodo->a.nombreAutobus);  
            Agregar(frente,fin,nuevoNodo);			           
            cout<<"Ingrese el precio del boleto: ";
            cin>>nuevoNodo->a.precio;
            cout<<"Ingrese el numero de boletos Disponibles: ";
            cin>>nuevoNodo->a.boletosDisponibles;
            break;
        case 2: ///  VER AUTOBUCES DISPONIBLES
        	if (colaVacia(frente)){  
				cout<<"Aun no hay Autobuces en este momento"<<endl;
				cout<<"Por favor espere...";
			}else{
            	mostrarAutobus(frente);
       		}
            break;
        case 3://COMPRAR BOLETO  
            if(colaVacia(frente)){
                cout<<"No hay autobuces en este momento espere..."<<endl;
            }else{
                while(true){ 
                    mostrarAutobus(frente); 
                    cout<<"Escriba el nombre del autobus : ";
                    getline(cin,nombrep);
                    getline(cin,nombrep);
                    boletoComprado=Buscarboleto(frente, nombrep); 
                    if(boletoComprado==NULL){ 
                    	cout<<endl;
                    	cout<<"****Error****"<<endl;
                        cout<<"Por favor vuelva a escribir el nombre del autobus"<<endl;
                        continue; 
                    }else{ 
                        if(boletoComprado->a.boletosDisponibles==0){ 
                            cout<<"No hay boletos disponibles :"<<endl;
                            continue; 
                        }else{ 
                            cout<<"Boleto comprado "<<endl;
                            boletoComprado->a.boletosDisponibles-=1; 
                            boletoComprado->a.boletosComprados+=1; 
                            break; 
                        }
                    }
                }
            }
            break;			
        case 4: //INGRESAR DATOS DEL PASAJERO 
			do{
				fflush(stdin);
				cout<<"Ingrese datos del pasajero"<<endl;
				cout<<"Nombre: ";
				getline(cin,p.Nombre);
				cout<<"Tipo de  pasajero: ";
				getline(cin,p.Tipo);
				cout<<"Origen: ";
				getline(cin,p.Origen);
				cout<<"Destino:";
				getline(cin,p.Destino);
				cout<<"Fecha:";
				getline(cin,p.Fecha);
				cout<<"Precio:";
				cin>>p.Costo;				
				cout<<"Desea ingresar mas pasajeros (s/n): "<<endl;
				cin>>dato;
				cout<<endl;
			}while (dato=='S' ||dato=='s');
			break;			
        case 5: 
			if (colaVacia(frente)){        
				cout<<"No hay Datos";
			}else{
				cout<<"Datos del pasajero\n";        
				cout<<endl;
				cout<<"Nombre: "<<p.Nombre<<endl;
				cout<<"Tipo de pasajero: "<<p.Tipo<<endl;
				cout<<"Origen: "<<p.Origen<<endl;
				cout<<"Destino: "<<p.Destino<<endl;
				cout<<"Fecha: "<<p.Fecha<<endl;
				cout<<"Precio: "<<p.Costo<<endl;				
			}
	
        break;
        case 6://MODIFICAR DATOS DEL PASAJERO
        	if (colaVacia(frente)){ 
				cout<<"No se han ingresado datos"<<endl;
			}else{
				modificarPasajero=Buscarboleto(frente,nombrep);
				if(modificarPasajero=NULL){	
					cout<<"Dato inexistente"<<endl;	
				}else{	
					fflush(stdin);
					cout<<"Ingrese los Nuevos datos del Pasajero"<<endl;
					cout<<"Nombre: ";
					getline(cin,p.Nombre);
					cout<<"Tipo de  pasajero: ";
					getline(cin,p.Tipo);				
					cout<<"Origen: ";
					getline(cin,p.Origen);
					cout<<"Destino:";
					getline(cin,p.Destino);
					cout<<"Fecha:";
					getline(cin,p.Fecha);
					cout<<"Precio:";
					cin>>p.Costo;					
			}
		}
		break; 
		
		case 7://MOSTAR MONTO DE LOS BOLETOS VENDIDOS
			if (colaVacia(frente)){
				cout<<"No hay ganancias"<<endl;
			}else{
        		mostrardt(frente,fin);
            	mostrarTotal();					
			}
		break;
        case 8: ///SALIR
        	mostrarTotal();	
        	cout<<endl;
			cout<<"Saliendo..."<<endl;
            break;
        }
        cout<<endl<<endl;
        system("pause");  system("cls");
    }while(opc!=8);

    return 0;
}

