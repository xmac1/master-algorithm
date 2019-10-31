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
        
    }
};