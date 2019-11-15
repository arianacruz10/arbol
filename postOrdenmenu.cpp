#include <iostream>
#include <stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *derecha;
	Nodo *izquierda;
};

void menu();
Nodo *hacerNodo(int);
void agregarNodo(Nodo *&,int);
void imprimirArbol(Nodo *,int);
void preOrden(Nodo*);
void enOrden(Nodo *);
void postOrden(Nodo *);

Nodo *arbol = NULL;

int main(){
	menu();
	
	getch();
	return 0;
}

void menu(){
	int dato, opcion,contador=0;
	
	do{
		cout<<"\t::::MENU:::"<<endl;
		cout<<"1.-insertar nodo"<<endl;
		cout<<"2.-Mostrar arbol"<<endl;
		cout<<"3-Preorden"<<endl;
		cout<<"4-En Orden"<<endl;
		cout<<"5-En PostOrden"<<endl;
		cout<<"6-Salir"<<endl;
		cout<<"selecciona una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\ningresa un numero: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					system("pause");
					break;
			case 2: cout<<"\nMuestra del arbol:\n\n";
					imprimirArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\nRecorrido en PreOrden: ";
					preOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
			case 4: cout<<"Recorrido en orden: ";
					enOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
			case 5: cout<<"Recorrido en PostOrden: ";
					postOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 6);
}

Nodo *hacerNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->derecha = NULL;
	nuevoNodo->izquierda = NULL;
	
	return nuevoNodo;
}
void agregarNodo(Nodo *&arbol, int n){
	if (arbol == NULL){
		Nodo *nuevoNodo = hacerNodo(n);
		arbol = nuevoNodo;
	}
	else{
		int valorRaiz= arbol->dato;
		if (n < valorRaiz){
			agregarNodo(arbol->izquierda,n);
		}
		else{
			agregarNodo(arbol->derecha,n);
		}
	}
	
}
void imprimirArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		imprimirArbol(arbol->derecha,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		imprimirArbol(arbol->izquierda,cont+1);
	}
}
void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izquierda);
		preOrden(arbol->derecha);
	}
}
void enOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		enOrden(arbol->izquierda);
		cout<<arbol->dato<<" - ";
		enOrden(arbol->derecha);
	}
}
void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		enOrden(arbol->izquierda);
		enOrden(arbol->derecha);
		cout<<arbol->dato<<" - ";
	}
}
