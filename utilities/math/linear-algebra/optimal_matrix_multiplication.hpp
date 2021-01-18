#pragma once

#include <cstdint>
#include <vector>

using std::vector;
using std::size_t;

using Matrix = vector<vector<double>>;


namespace utilities::math::linear_algebra {
    auto optimal_order_of_matrix_multiplication(const std::vector<size_t>& c, Matrix& M, Matrix &change ) -> size_t {
        size_t left { 0 };
        size_t right { 0 };
        size_t cost { 0 };
        size_t i { 0 };
        size_t j { 0 };
        size_t k { 0 };
        size_t n { c.size() - 1 };

        for (left = 1; left <= n; left += 1) {
            M[left][left] = 0;
        }

        for (k = 1; k < n; k += 1) {
            // k is right - left
            for (left = 1; left <= n - k; left += 1) {
                // for each position
                right = left + k;
                M[left][left] = INT_MAX;
                for (i = let; i < right) {

                }
            }
        }


        return 2;
    }




} // namespace utilities::math::linear_algebra
