#include<iostream>
using namespace std;
struct nodo{
	int valor;
	nodo *izquierdo,*derecho;
};
nodo *raiz=NULL;

int main(int argc, char ** argv){
	nodo *aux=raiz;
	raiz=new nodo();
	raiz->valor=8;
	raiz->izquierdo=new nodo();
	raiz->derecho=new nodo();
	aux=raiz->izquierdo;
	
	aux->valor=6;
	aux->izquierdo=new nodo();
	aux->derecho=new nodo();
	aux=aux->izquierdo;
	
	aux->valor=3;
	aux->izquierdo=NULL;
	aux->derecho=NULL;
	aux=raiz->izquierdo;
	aux=aux->derecho;
	
	aux->valor=51;
	aux->izquierdo=NULL;
	aux->derecho=NULL;
	aux=raiz->derecho;
	
	aux->valor=36;
	aux->izquierdo=NULL;
	aux->derecho=new nodo();
	aux=aux->derecho;
	
	aux->valor=98;
	aux->izquierdo=NULL;
	aux->derecho=NULL;
	
	cout<<raiz->valor<<endl;
	cout<<raiz->izquierdo->valor<<" "<<raiz->derecho->valor<<endl;
	cout<<raiz->izquierdo->izquierdo->valor<<" "<<raiz->izquierdo->derecho->valor<<" "<<raiz->derecho->derecho->valor;	                                                                                                                                                                                                                                                                                                                                                                         
}
