// graph.h
// --------------------------------------------
// A C++ directed graph adjacency list implementation
// using std::map
//
// @author: Sam Prescott

#ifndef GRAPH_H
#define GRAPH_H

#include <map>

template<typename t1, typename t2>
class Graph {
    public:
        Graph() : adj_list_() {}
        ~Graph() {}
        void add_edge();
    
    private:
        std::map<t1, t2> adj_list_;
};

#endif
