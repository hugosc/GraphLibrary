#include <vector>

struct edge {
    int key;
    struct edge* next;
    int weight;
}



template <class T> class node {
    public :
         node (T*, node*, int);
         node (T*, node*);
         node~ (void);
         T getInfo (void);
         int getColor (void);
         node* getParent (void);
         int getDegree (void);
         void addEdge (int);
         void deleteEdge (int);

    private :
        int color, degree;
        node* parent;
        edge* adj_list;
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
