#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>



void main(){

	Grafo* g = criarGrafo();


	for(int i = 0; i < 10; i++){
	
		inserirAresta(i, i+1, 0, g);
	}

	imprimirGrafo(g);


}
