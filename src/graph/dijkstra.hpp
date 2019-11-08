#include "graph.hpp"
#include <bits/stdc++.h>
#include "minheap.hpp"

struct Dist {
    int index;
    int length;
    int pre;
};

void Dijkstra(Graph& G, int s, Dist* & D) {
    D = new Dist[G.VerticesNum()];
    for (int i = 0; i < G.VerticesNum(); i++) {
        G.Mark[i] = 0;
        D[i].index = i;
        D[i].length = INT_MAX;
        D[i].pre = s;
    }

    D[s].length = 0;

    MinHeap<Dist> H(G.EdgeNum());
    H.Insert(D[s]);
    for (int i = 0; i < G.VerticesNum(); i++) {
        bool FOUND = true;
        Dist d;
        while(!H.isEmpty()) {
            d = H.RemoveMin();
            if (G.Mark[d.index] == 0) {
                FOUND = true;
                break;
            }
        }
        if (!FOUND) {
            break;
        }
        int v = d.index;
        G.Mark[v] = 1;
        for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
            if (D[G.ToVertex(e)].length > (D[v].length + G.Weight(e))) {
                D[G.ToVertex[e]].length = D[v].length + G.Weight(e);
                D[G.ToVertex(e)].pre = v;
                H.Insert(D[G.ToVertex(e)]);
            }
        }
    }
}