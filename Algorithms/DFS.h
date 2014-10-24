#include "../GraphStructure/Graph.h"
#include <iostream>

template <class T> void DFS_rec (Graph<T>& g, node<T>& o) {
    o.color = GREY;

    for (int i = 0;i < o.getDegree() ; i++) {
        if (g.node_at(o.neighbour(i)).color == WHITE)
            DFS_rec (g,g.node_at(o.neighbour(i)));
    }

    std::cout << o.getInfo() << std::endl;
    o.color = BLACK;
}

template <class T> void DFS (Graph<T>& g) {

    for (int i=0;i < g.n_vertices(); i++) {
        g.node_at(i).color = WHITE;
    }

    for (int i=0;i < g.n_vertices(); i++) {
        node<T>& u = g.node_at(i);
        if (u.color == WHITE) {
            DFS_rec(g,u);
        }
    }
}
