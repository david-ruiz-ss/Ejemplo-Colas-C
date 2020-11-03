#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//se declara el nodo y se le eñade el punteri siguiente
struct Nodo{
	char dato;
	Nodo *siguiente;	
};

//prototipos de la funcion
void menu();
void insertarCola(Nodo *&,Nodo *&,char);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,char &);

int main(){
	//se mnada a llamar a la funcion menu
	menu();
	
	getch();
	return 0;
}
	
void menu(){
	int opc;
	char dato;
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
		//se muestra el menu de opciones
		cout<<"\t.:MENU:.\n";
		cout<<"1. Insertar un caracter a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos de la cola"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc; 
		
		//creacion del menu de opciones
		switch(opc){
			case 1: cout<<"\nIngrese el caracter para agregar a la cola: ";
					cin>>dato;
					insertarCola(frente,fin,dato);
					break;
			case 2: cout<<"\nMostrando los elementos de la cola: ";
					while(frente != NULL){
						suprimirCola(frente,fin,dato);
						if(frente != NULL){
							cout<<dato<<" , ";
						}
						else{
							cout<<dato<<".";
						}
					}
					cout<<"\n";
					system("pause");
					break;
			case 3: break;
		}
		system("cls");
	}while(opc != 3);
}

//funcion insertar
void insertarCola(Nodo *&frente,Nodo *&fin,char n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

 //funcion para determinar si la cola esta vacia
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false; 
}

//funcion suprimir
void suprimirCola(Nodo *&frente,Nodo *&fin,char &n){
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}
