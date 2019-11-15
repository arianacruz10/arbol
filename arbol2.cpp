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

Nodo *hacernodo(int);
void agregarNodo(Nodo *&,int);

Nodo *arbol = NULL;

int main(){
	menu();
	  
	getch();
	return 0;
}

void menu(){
	int dato, opcion;
	
	do{
		cout<<"\t::::MENU::::"<<endl;
		cout<<"1.-insertar nodo"<<endl;
		cout<<"2-Salir"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\ningresa un numero: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 2);
}

Nodo *hacernodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->derecha = NULL;
	nuevoNodo->izquierda = NULL;
	
	return nuevoNodo;
}
void agregarNodo(Nodo *&arbol, int n){
	if (arbol == NULL){
		Nodo *nuevoNodo = hacernodo(n);
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
