#include <bits/stdc++.h>
#include <queue>
#include <iostream>

class IGraph {
    class Edge;
public:
    int VeticesNum();
    int EdgeNum();
    Edge FirstEdge(int oneVertex);
    Edge NextEdge(Edge preEdge);

    bool setEdge(int fromVertex, int toVertex, int weight);
    bool delEdge(int fromVertex, int toVertex);
    bool IsEdge(Edge oneEdge);
    int FromVertex(Edge oneEdge);
    int ToVertex(Edge oneEdge);
    int Weight(Edge oneEdge);
};

class Edge {
public:
    int from, to, weight;
    Edge() {from = -1;; to = -1; weight=0;}
    Edge(int f, int t, int w) {from = f; to = t; weight = w;}
};

class Graph {
public:
    int numVertex;
    int numEdge;
    int * Mark;
    int * Indegree;
    Graph(int numVert) {
        numVertex = numVert;
        numEdge = 0;
        Indegree = new int[numVertex];
        Mark = new int[numVertex];
        for (int i = 0; i < numVertex; i++) {
            Mark[i] = 0;
            Indegree[i] = 0;
        }
    }
    ~Graph() {
        delete [] Mark;
        delete [] Indegree;
    }

    int VerticesNum() {
        return numVertex;
    }

    bool IsEdge(Edge oneEdge) {
        if (oneEdge.weight > 0 && oneEdge.weight < INT_MAX && oneEdge.to > 0) {
            return true;
        }
        return false;
    }
    Edge FirstEdge(int oneVertex);
    Edge NextEdge(Edge preEdge);
    int FromVertex(Edge oneEdge);
    int ToVertex(Edge oneEdge);
    int Weight(Edge oneEdge);

};


void Visit(Graph& G, int v);

void DFS(Graph& G, int v) {
    G.Mark[v] = 1;
    Visit(G, v);
    for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
        if (G.Mark[G.ToVertex(e)] == 0) {
            DFS(G, G.ToVertex(e));
        }       
    }
}

void BFS(Graph& G, int v) {
    using namespace std;
    queue<int> Q;
    Visit(G, v);
    G.Mark[v] = 1;
    Q.push(v);
    while (!Q.empty()) {
        int vertex = Q.front();
        Q.pop();
        for (Edge e = G.FirstEdge(vertex); G.IsEdge(e); e = G.NextEdge(e)) {
            if (G.Mark[vertex] == 0) {
                Visit(G, vertex);
                G.Mark[vertex] = 1;
                Q.push(G.ToVertex(e));
            }
        }
    }
}

void TopsortByQueue(Graph& G) {
    for (int i = 0; i < G.VerticesNum(); i++) {
        G.Mark[i] = 0;
    }

    using std::queue;
    queue<int> Q;
    for (int i = 0; i < G.VerticesNum(); i++) {
        if (G.Indegree[i] == 0) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        Visit(G, v);
        G.Mark[v] = 1;
        for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
            G.Indegree[G.ToVertex[v]]--; // 入度
            if (G.Indegree[G.ToVertex[v]] == 0) {
                Q.push(G.ToVertex(e));
            }
        }
    }

    for (int i = 0; i < G.VerticesNum(); i++) {
        if (G.Mark[i] == 0) {
            std::cout << "cycle graph" << std::endl;
            break;
        }
    }
}