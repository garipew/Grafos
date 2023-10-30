
typedef struct aresta {
	
	struct vertice* destino;
	int peso;

	struct aresta* proximaAresta;

} Aresta;


typedef struct vertice{
	
	int quantidadeArestas;
	int id;

	Aresta* primeiraAresta;
	Aresta* ultimaAresta;
	
	struct vertice* proximoVertice;
} Vertice;


typedef struct grafo{
	
	Vertice* primeiroVertice;
	Vertice* ultimoVertice;

	int quantidadeVertices;
	int quantidadeArestas;

} Grafo;



Grafo* criarGrafo();
Vertice* criarVertice(int);
Aresta* criarAresta(int, int, Grafo*);
void inserirVertice(Vertice*, Grafo*);
void inserirAresta(int, int, int, Grafo*);
void removerVertice(int, Grafo*);
void removerAresta(int, int, Grafo*);
void apagarGrafo(Grafo*);
void imprimirGrafo(Grafo*);
