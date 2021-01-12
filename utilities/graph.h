#ifndef UTILITIES_GRAPH_H
#define UTILITIES_GRAPH_H

#include "types.h"

namespace utilities::graph {

    struct Edge {
        u32 from;
        u32 to;
        u32 weight;

        Edge(u32 from, u32 to, u32 weight) : 
            from{from}, to{to}, weight{weight}
    };


    /// Prims algorithm for minimum spanning tree
    void primMST(const Graph& graph) {

    }
    
    /// Kruskal's algorithm is a greedy algorithm to find the minimum spanning tree.
    ///     1. Sort the edges in ascending order according to their weights.
    ///     2. At every step, choose the smallest edge(with minimum weight).
    ///        if this edge forms a **cycle** with the MST formed so far,
    ///        discard the edge, else add it to the MST.
    ///     3. Repeat step 2, until all vertices are not present in the MST.
    void kruskalMST() {

    }


}  // namespace utilities::graph


#endif // UTILITIES_GRAPH_H
