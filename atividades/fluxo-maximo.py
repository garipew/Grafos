import networkx as nx
from networkx.algorithms.flow import *

G = nx.DiGraph()

arquivo_entrada = open("input.txt")


for linha in arquivo_entrada:
    vertices = linha.split()
    G.add_edge(vertices[0], vertices[1], capacity=vertices[2])

arquivo_entrada.close()

for edge in G.edges:
    print(G.get_edge_data(edge[0], edge[1]))
