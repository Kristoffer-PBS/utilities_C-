#pragma once

#include <algorithm>
#include <cstdint>
#include <cassert>
#include <vector>

using namespace std;


const int REACHES_NEGATIVE_CYCLE = -100'000'000;

namespace utilities::ds::graph {

class Graph {
   private:
    vector<vector<int>> adj_matrix;
    size_t n_edges = 0;

   public:
    Graph(const unsigned int vertices) : adj_matrix(vertices) {
        for (auto& entry : adj_matrix) {
            entry.resize(vertices, 0);
        }
    }

    auto add_edge(const int from, const int to, const int weight) -> void {
        assert(0 <= from and from < size());
        assert(0 <= to and to < size());

        adj_matrix[from][to] = weight;
        adj_matrix[to][from] = weight;
    }

    auto size() const -> vector<vector<int>>::size_type {
        return adj_matrix.size();
    }
    auto number_of_edges() const -> std::size_t { return n_edges; }

    auto floyd_warshall() -> void {
        auto dp = vector<vector<int>>(size());
        for (auto& v : dp) {
            v.resize(size(), 0);
        }

        auto next = vector<vector<int>>(size());
        for (auto& v : dp) {
            v.resize(size(), 0);
        }

        // Copy adjacentcy matrix and setup 'next' and dynamic programming matrix
        // for path compression.
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < size(); j++) {
                if (adj_matrix[i][j] != INT_MAX) {
                    next[i][j] = j;
                }
                dp[i][j] = adj_matrix[i][j];
            }
        }
        // compute all pairs shortest paths
        for (int k = 0; k < size(); k++) {
            for (int i = 0; k < size(); i++) {
                for (int j = 0; j < size(); j++) {
                    if (dp[i][k] + dp[k][j] < dp[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }


        // Identify negative cycles by propagating the value 'INT_MIN'
        // to every edge that is part of or reaches into a negative cycle.
        for (int k = 0; k < size(); k++) {
            for (int i = 0; k < size(); i++) {
                for (int j = 0; j < size(); j++) {
                    if (dp[i][k] + dp[k][j] < dp[i][j]) {
                        dp[i][j] = INT_MIN;
                        next[i][j] = REACHES_NEGATIVE_CYCLE;
                    }
                }
            }
        }
    }

};

}  // namespace utilities::ds::graph

