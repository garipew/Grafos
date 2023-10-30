#define LISTA
#ifndef GRAFO
	#define GRAFO
	#include "grafo.h"
#endif

typedef struct item{

	Vertice* vertice;
	int indice;

	struct item* proximo;

} Item;


typedef struct lista{
	
	Item* primeiro;
	Item* ultimo;

	int quantidade;

} Lista;


Lista* criarLista();
Item* criarItem(Vertice*);
void inserirItem(Item*, Lista*);
void removerItem(int, Lista*);
void apagarLista(Lista*);
void imprimirLista(Lista*);
