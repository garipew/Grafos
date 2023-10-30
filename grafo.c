#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>


Vertice* criarVerticeInicial(){

	Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));

	vertice->quantidadeArestas = 0;
	vertice->id = -1;

	vertice->primeiraAresta = NULL;
	vertice->ultimaAresta = NULL;

	return vertice;

}


Aresta* criarArestaInicial(){

	Aresta* aresta = (Aresta*)malloc(sizeof(Aresta));

	aresta->destino = NULL;
	aresta->peso = -1;
	
	aresta->proximaAresta = NULL;

	return aresta;
	
}


Grafo* criarGrafo(){

	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

	grafo->primeiroVertice = criarVerticeInicial();
	grafo->ultimoVertice = grafo->primeiroVertice;

	grafo->primeiroVertice->proximoVertice = NULL;
	grafo->ultimoVertice->proximoVertice = NULL;	
	
	int quantidadeVertices = 0;
	int quantidadeArestas = 0;
	
	return grafo;
}


Vertice* criarVertice(int id){

	Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));

	vertice->quantidadeArestas = 0;
	vertice->id = id;

	vertice->primeiraAresta = criarArestaInicial();
	vertice->ultimaAresta = vertice->primeiraAresta;

	vertice->primeiraAresta->proximaAresta = NULL;
	vertice->ultimaAresta->proximaAresta = NULL;


	return vertice;
}


Vertice* buscarVertice(int indice, Grafo* grafo){

	Vertice* buscado = grafo->primeiroVertice->proximoVertice;

	while(buscado != NULL){
		if(buscado->id == indice)
			return buscado;
		buscado = buscado->proximoVertice;
	}

	return buscado;
}


Aresta* criarAresta(int destino, int peso, Grafo* grafo){

	Aresta* aresta = (Aresta*)malloc(sizeof(Aresta));
	
	Vertice* verticeDestino = buscarVertice(destino, grafo);
	
	if(verticeDestino == NULL){
		verticeDestino = criarVertice(destino);
		inserirVertice(verticeDestino, grafo);
	}

	aresta->destino = verticeDestino;
	aresta->peso = peso;
	
	aresta->proximaAresta = NULL;

	return aresta;

}


void inserirVertice(Vertice* vertice, Grafo* grafo){

	Vertice* antigoUltimo = grafo->ultimoVertice;

	antigoUltimo->proximoVertice = vertice;
	grafo->ultimoVertice = vertice;
	
	grafo->quantidadeVertices++;

	vertice->proximoVertice = NULL;

}


void inserirAresta(int origem, int destino, int peso, Grafo* grafo){
	
	Aresta* novaAresta = criarAresta(destino, peso, grafo);
	
	Vertice* verticeOrigem = buscarVertice(origem, grafo);
	if(verticeOrigem == NULL){
		verticeOrigem = criarVertice(origem);
		inserirVertice(verticeOrigem, grafo);
	
	}

	Aresta* antigaUltima = verticeOrigem->ultimaAresta;

	antigaUltima->proximaAresta = novaAresta;
	verticeOrigem->ultimaAresta = novaAresta;

	novaAresta->proximaAresta = NULL;

	verticeOrigem->quantidadeArestas++;
	grafo->quantidadeArestas++;

}


void removerAresta(int destino, int origem, Grafo* grafo){
	

	Vertice* verticeOrigem = buscarVertice(origem, grafo);

	Aresta* anteriorRemovida = verticeOrigem->primeiraAresta->proximaAresta;
	Aresta* removida;

	while(anteriorRemovida->proximaAresta->destino->id != destino){
		
		if(anteriorRemovida->proximaAresta == NULL)
			return;
		
		anteriorRemovida = anteriorRemovida->proximaAresta;
	
	}

	removida = anteriorRemovida->proximaAresta;

	anteriorRemovida->proximaAresta = removida->proximaAresta;

	if(anteriorRemovida->proximaAresta == NULL)
		verticeOrigem->ultimaAresta = anteriorRemovida;
	
	free(removida);
	verticeOrigem->quantidadeArestas--;
	grafo->quantidadeArestas--;


}


void removerVertice(int indice, Grafo* grafo){

	Vertice* anteriorRemovido = grafo->primeiroVertice->proximoVertice;
	Vertice* removido;

	while(anteriorRemovido->proximoVertice->id != indice){

		if(anteriorRemovido == NULL)
			return;
	
		anteriorRemovido = anteriorRemovido->proximoVertice;
	
	}

	removido = anteriorRemovido->proximoVertice;

	while(removido->quantidadeArestas > 0){
		
		removerAresta(removido->primeiraAresta->proximaAresta->destino->id, removido->id, grafo);
	}
	
	anteriorRemovido->proximoVertice = removido->proximoVertice;
	if(anteriorRemovido->proximoVertice == NULL)
		grafo->ultimoVertice = anteriorRemovido;

	free(removido);

	grafo->quantidadeVertices--;

}


void apagarGrafo(Grafo* grafo){

	while(grafo->quantidadeVertices > 0){
		
		removerVertice(grafo->primeiroVertice->proximoVertice->id, grafo);
	
	}
	
	free(grafo);


}


void imprimirGrafo(Grafo* g){


	printf("%d vertices e %d arestas\n", g->quantidadeVertices, g->quantidadeArestas);



}
