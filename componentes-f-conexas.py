import igraph as ig


G = ig.read("input.txt")

k = 0

V = [v for v in G.vs]

W = []

while len(V) != 0:

    v = V[0]
    R = [v]
    r = [v]
    N = []
    n = []
    W.append(k)

    while True:

        for x in R:
            N.extend([a for a in x.neighbors(mode="out")])
        N = [x for x in N if x not in R]
        N = [x for x in N if x in V]

        if len(N) == 0:
            break
        W[k] = N
        R.extend(W[k])

    while True:
        for x in r:
            n.extend([a for a in x.neighbors(mode="in")])
        n = [x for x in n if x not in r]
        n = [x for x in n if x in V]

        if len(n) == 0:
            break
        W[k] = n
        r.extend(W[k])

    W[k] = [x for x in R if x in r]

    V = [x for x in V if x not in W[k]]
    k += 1

output = open('output.txt', 'w')

for k in W:
    for v in k:
        output.write(f'{v.index} ')
    output.write("\n")

output.close()

