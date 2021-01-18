#pragma once

#include <vector>


namespace utilities::sort {
    // insertion sort in-place
    // sorted in descending order
    // complexity O(N^2)
    template <typename Comparable>
    void insertion_sort(std::vector<Comparable>& array) {
        using std::size_t;

        for (size_t i = 1; i < array.size(); i += 1) {
            int j = i;

            for (;j > 0 && array[j - 1] > array[j]; j -= 1) {
                std::swap(array[j - 1], array[j]);
            }

            /* Comparable tmp = std::move(array[i]); */
            /* int j; */

            /* for (j = i; j > 0 && tmp < array[j - 1]; j -= 1) { */
            /*     array[j] = std::move(array[j - 1]); */
            /* } */

            /* array[j] = std::move(tmp); */
        }
    }


}
