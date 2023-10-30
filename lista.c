#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criarLista(){

	Lista* lista = (Lista*)malloc(sizeof(Lista));

	lista->primeiro = criarItem(NULL);
	lista->ultimo = lista->primeiro;
	
	lista->quantidade = 0;
	
	return lista;

}


Item* criarItem(Vertice* vertice){

	Item* item = (Item*)malloc(sizeof(Item));

	item->vertice = vertice;
	item->indice = 0;

	item->proximo = NULL;
	
	return item;

}


void inserirItem(Item* novoItem, Lista* lista){

	Item* antigoUltimo = lista->ultimo;

	antigoUltimo->proximo = novoItem;
	
	lista->ultimo = novoItem;
	lista->quantidade++;

}


void removerItem(int indiceRemovido, Lista* lista){

	Item* itemAnteriorRemovido = lista->primeiro->proximo;
	Item* itemRemovido;

	if(indiceRemovido > lista->quantidade)
		return;	

	while(itemAnteriorRemovido->proximo->indice != indiceRemovido){
		
		itemAnteriorRemovido = itemAnteriorRemovido->proximo;

	}

	itemRemovido = itemAnteriorRemovido->proximo;

	itemAnteriorRemovido->proximo = itemRemovido->proximo->proximo;
	lista->quantidade--;

	if(itemRemovido->proximo == NULL)
		lista->ultimo = itemRemovido;

	free(itemRemovido);

}


void apagarLista(Lista* lista){

	Item* primeiroItem = lista->primeiro;

	while(lista->quantidade > 0){
	
		removerItem(primeiroItem->proximo->indice, lista);

	}

	free(primeiroItem);
	free(lista);

}


void imprimirLista(Lista* lista){

	Item* itemAtual = lista->primeiro->proximo;

	while(itemAtual != NULL){

		printf("%d ", itemAtual->indice);
	
		itemAtual = itemAtual->proximo;
	
	}

	printf("\n");

}
