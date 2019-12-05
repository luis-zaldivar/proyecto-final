#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int fecha,dia,opcion,mes;
	cout<<"\t\t ...::MENU::...\n 1.-Inserter pedido \n 2.-Eliminar pedido \n 3.-Buscar pedido\n 4.-salir\n";
	cin>>opcion;
	do{
	switch(opcion){
			case 1:
			cout<<"inserte el mes de llegada: ";
			cin>>mes;
				if (mes==1){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>31){
						cout<<"error dia incorrecto\n";
					}
					cout<<"inserte el nombre del pedido";
				}
				if (mes==2){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>29){
						cout<<"error dia incorrecto\n";
					}
				}
				if (mes==3){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>31){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==4){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>30){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==5){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>30){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==6){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>30){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==6){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>30){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==7){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>31){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==8){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>31){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==9){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>30){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==10){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>31){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==11){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>30){
						cout<<"error dia incorrecto\n";
					}
				}if (mes==12){
					cout<<"inserte el dia de llegada: ";
					cin>>dia;
					if(dia<=0){
						cout<<"error dia incorrecto\n";
					}else if(dia>31){
						cout<<"error dia incorrecto\n";
					}
				}
			
			
			break;
	}	
	}while (opcion==4);
	return 0;
}
