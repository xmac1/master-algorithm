#include "graph.hpp"


struct ListUnit {
    int vertex;
    int weight;
};

template <class Elem>
class Link {
public:
    Elem element;
    Link * next;
    Link(const Elem& elemval, Link *nextval = nullptr) {
        element = elemval;
        next = nextval;
    }

    Link(Link * nextval = nullptr) {
        next = nextval;
    }
};

template <class Elem>
class LList {
public:
    Link<Elem> * head;
    LList() {
        head = new Link<Elem>();
    }
};

class Graphl : public Graph {
private:
    LList<ListUnit> * graList;
public:
    Graphl(int numVert) : Graph(numVert) {
        graList = new LList<ListUnit>[numVertex];
    }

    Edge FirstEdge(int oneVertex) {
        Edge edge;
        edge.from = oneVertex;
        Link<ListUnit> * tmp = graList[oneVertex].head; 
        if (tmp->next != nullptr) {
            edge.to = tmp->next->element.vertex;
            edge.weight = tmp->next->element.weight;
        }
        return edge;
    }

    Edge NextEdge(Edge oneEdge) {
        Edge edge;
        edge.from = oneEdge.from;
        Link<ListUnit> * tmp = graList[oneEdge.from].head;
        while (tmp->next != null && tmp->next->element.vertex <= oneEdge.to) {
            tmp = tmp->next;
        }
        if(tmp->next != nullptr) {
            edge.to = tmp->next->element.to;
            edge.weight = tmp->next->element.weight;
        }
        return edge;
    }
};