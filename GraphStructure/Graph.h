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
}



template <class T> class node {
    public :
         node (T, node*, int);
         node~ (void);
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
}

template <class T> node<T>::node<T> (T data, node* prt, int clr) {
    info = data;
    parent = prt;
    color = clr;
    degree = 0;
}

template <class T> T node<T>::getInfo () {
    return info;
}

template <class T> int node<T>::getDegree () {
    return degree;
}

template <class T> void addEdge (int s, int weight) {
    edge* new_edge = new edge;
    new_edge->key = s;
    new_edge->weight = weight;

    new_edge->next = adj_list;
    adj_list = new_edge;
}

template <class T> void deleteEdge (int s) {
    
}

template <class T> class Graph {
    public :
        Graph (void);
        Graph (std::vector<T>);
        void addVertex (T*);
        void deleteVertex (int);
        void addEdge (int, int);
        void deleteEdge (int, int);
        int n_vertices (void);
        int n_edges (void);
    private :
        int nv;
        int ne;
        std::vector<node<T>> v_list;
}

#endif
