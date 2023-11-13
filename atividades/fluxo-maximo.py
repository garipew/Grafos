import networkx as nx
from networkx.algorithms.flow import *

G = nx.DiGraph()

arquivo_entrada = open("input.txt")


for linha in arquivo_entrada:
    vertices = linha.split()
    G.add_edge(vertices[0], vertices[1], capacity=int(vertices[2]))

arquivo_entrada.close()

fila_vertices = ['S']


while len(fila_vertices) > 0:
    print(fila_vertices)
    alcancaveis = [n for n in G[fila_vertices[0]]]
    fila_vertices.extend(alcancaveis)
    fila_vertices.pop(0)





