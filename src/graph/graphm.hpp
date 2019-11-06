#include "graph.hpp"


class Graphm : public Graph {
private:
    int * *matrix;
public:
    Graphm(int numVert) : Graph(numVert) {
        int i, j;
        matrix = (int **) new int * [numVertex];
        for (i = 0; i < numVertex; i++) {
            matrix[i] = new int[numVertex];
        }
        for (i = 0; i < numVertex; i++) {
            for (i = 0; i < numVertex; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    ~Graphm() {
        for (int i = 0; i < numVertex; i++){
            delete [] matrix[i];
        }
    }

    Edge FirstEdge(int oneVetext) {
        Edge edge;
        edge.from = oneVetext;
        for (int i = 0; i < numVertex; i++) {
            if (matrix[oneVetext][i] > 0) {
                edge.to = i;
                edge.weight = matrix[oneVetext][i];
                return edge;
            }
        }
        return edge;
    }
    
    Edge NextEdge(Edge edge) {
        Edge nextEdge;
        nextEdge.from = edge.from;
        if (edge.to < numVertex) {
            for (int i = edge.to+1; i < numVertex; i++) {
                if (matrix[edge.from][i] != 0) {
                    nextEdge.to = i;
                    nextEdge.weight = matrix[edge.from][i];
                    break;
                }
            }
        }
        return nextEdge;
    }

    void setEdge(int from, int to, int weight) {
        if (matrix[from][to] <= 0 ) {
            numEdge++;
            Indegree[to]++;
        }
        matrix[from][to] = weight;
    }

    void delEdge(int from, int to) {
        if (matrix[from][to] > 0) {
            numEdge--;
            Indegree[to]--;
        }
        matrix[from][to] = 0;
    }
};