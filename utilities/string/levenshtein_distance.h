#ifndef _UTILITIES_STRING_LEVENSHTEIN_H
#define _UTILITIES_STRING_LEVENSHTEIN_H

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

#include "../data_structures/matrix.h"

namespace utilities {
    namespace string {
        using std::size_t;


        ///
        /// the Levenshtein distance between two strings is the minimum number of single-character
        /// edits (insertions, deletions, substitutions) required to change one word into the other.

        /// COMPLEXITY: O(?)

        // an "edit" is defined by either an insertion of a character, a deletion of a
        // character, or a replacement of a character.

        // When the entire table has been built, the desired distance is in the table in the
        // last row and column, representing the distance between all of the characters in s
        // and all the characters in t.

        // the strings are 1-indexed
        unsigned int levenshtein_distance(std::string_view N, std::string_view M, bool case_sensitive = true, bool trim_beginning_and_trailing_white_space = true) noexcept {
            size_t n = N.length();
            size_t m = M.length();

            /* std::cout << "n = " << n << "\tm = " << m << std::endl; */
            
            // if any of the strings are 0 in length the edit distance
            // will simply be the length of the other string. 
            if (n == 0) {
                return m;
            } else if (m == 0) {
                return n;
            }
            
            // use a matrix for dynamic programming
            utilities::data_structures::Matrix<int> lut(n+1, m+1, 0);
            /* std::cout << "row = " << lut.nrows() << "\tcol = " << lut.ncols() << std::endl; */
            /* int **lut = new int*[n+1]; */
            /* for (int i = 0; i < n + 1; i++) { */
            /*     *lut = new int[m+1]; */
            /* } */

            /* int *lut = new int[n+1 * m+1]; */



            for (int i = 0; i < n + 1; i++) {
                lut[i][0] = i;
            }

            for (int i = 0; i < m + 1; i++) {
                lut[0][i] = i;
            }
            

            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < m + 1; j++) {
                    int substitution_cost = N[i-1] == M[j-1] ? 0 : 1;

                    /* std::cout << "N[i] = " << N[i-1] << "\tM[j] = " <<  M[j-1] << std::endl; */

                    assert(substitution_cost == 0 || substitution_cost == 1);

                    /* std::cout << "lut[i-1][j-1]] + substitution_cost = " <<  "lut[i-1][j-1]" << lut[i-1][j-1] << " + "<< substitution_cost << std::endl; */

                    lut[i][j] = std::min({
                        lut[i-1][j] + 1,
                        lut[i][j-1] + 1,
                        lut[i-1][j-1] + substitution_cost
                    });
                   
                    /* std::cout << lut << "\n\n" << std::endl; */
                }
            }

            std::cout << lut;
            
            /* return lut[n][m]; */
            return lut[n-1][m-1];




            /* utilities::data_structures::Matrix<int> m(a.length(), b.length(), 0); */

            /* for (int i = 0; i < m.ncols(); i++) { */
            /*     m[0][i] = i; */
            /* } */

            /* for (int i = 0; i < m.nrows(); i++) { */
            /*     m[i][0] = i; */
            /* } */

            /* for (int j = 1; j < m.ncols(); j++) { */
            /*     for (int i = 1; i < m.nrows(); i++) { */
            /*         int substitution_cost = a[i] == b[j] ? 0 : 1; */

            /*         m[i][j] = std::min({ */
            /*             m[i-1][j] + 1,                   // deletion */
            /*             m[i][j-1] + 1,                   // insertion */
            /*             m[i-1][j-1] + substitution_cost  // substitution */
            /*         }); */
            /*     } */
            /* } */


            /* // std::mismatch */

            /* // the element in the botton-right index is the edit distance metrix */
            /* return m[m.nrows() - 1][m.ncols() - 1]; */
        }

        // function alias  https://www.fluentcpp.com/2017/10/27/function-aliases-cpp/
        // const auto lev = levenshtein_distance;
        // auto& lev = levenshtein_distance;


    } // namespace string
} // namespace utilities


#endif // _UTILITIES_STRING_LEVENSHTEIN_H
