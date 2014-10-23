#include <vector>
#include <stdlib.h>

#ifndef Graph_H_
#define Graph_H_

#define WHITE 0
#define GREY 1
#define BLACK 2


struct edge {
    int key;
    struct edge* next;
    int weight;
};



template <class T> class node {
    public :
         node (T, node*, int);
        // node~ (void);
         T getInfo (void);
         int getDegree (void);
         void addEdge (int, int);
         void deleteEdge (int);

         int color;
         node<T>* parent;

    private :
        int degree;
        T info;
        edge* adj_list;
};

template <class T> node<T>::node (T data, node* prt, int clr) {
    info = data;
    parent = prt;
    color = clr;
    degree = 0;
    adj_list = NULL;
}

template <class T> T node<T>::getInfo () {
    return info;
}

template <class T> int node<T>::getDegree () {
    return degree;
}
//endp stands for end point
template <class T> void node<T>::addEdge (int endp, int weight) {
    edge* new_edge = new edge;
    new_edge->key = endp;
    new_edge->weight = weight;

    new_edge->next = adj_list;
    adj_list = new_edge;
}
//endp stands for end point
template <class T> void node<T>::deleteEdge (int endp) {
    edge* aux1 = adj_list;
    edge* aux2 = NULL;

    while (aux1 != NULL && aux1->key != endp) {
        aux1 = aux1->next;
        aux2 = aux1;
    }

    if (aux2 == NULL && aux1 != NULL) {
        delete aux1;
        adj_list = NULL;
    }

    else if (aux1 != NULL) {
        aux2->next = aux1->next;
        delete aux1;
    }
}

template <class T> class Graph {
    public :
        Graph (void);
        Graph (std::vector<T>&);
        void addVertex (T);
        void deleteVertex (int);
        void addEdge (int, int);
        void deleteEdge (int, int);
        int n_vertices (void);
        int n_edges (void);
    private :
        int nv;
        int ne;
        std::vector<node<T>> v_list;
};

template <class T> Graph<T>::Graph () {
    nv = 0;
    ne = 0;
}

template <class T> Graph<T>::Graph (std::vector<T> &node_data) {
    for (int i=0;i<node_data.size();i++) {
        v_list.emplace_back(node_data[i],NULL,WHITE);
        nv++;
    }
}

template <class T> void Graph<T>::addVertex (T data) {
    v_list.push_back(node<T>(data,NULL,WHITE));
    nv++;
}

template <class T> void Graph<T>::deleteVertex (int v) {
    if (v < v_list.size()) {
        v_list.erase(v_list.begin()+v);
        nv--;
    }
}

template <class T> void Graph<T>::addEdge (int startp, int endp) {
    if (startp >= 0 && endp < nv) {
        v_list[startp].addEdge(endp,1);
        ne++;
    }
    else { std::cerr << "Non existant vertex or vertices.\n"; }
}

template <class T> void Graph<T>::deleteEdge (int startp, int endp) {
    if (startp >= 0 && endp < nv) {
        v_list[startp].deleteEdge(endp);
    }
    else { std::cerr << "Non existant vertex or vertices.\n"; }
}

template <class T> int Graph<T>::n_vertices () {
    return nv;
}

template <class T> int Graph<T>::n_edges () {
    return ne;
}

#endif
