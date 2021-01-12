#ifndef _UTILITIES_DATA_STRUCTURES_H
#define _UTILITIES_DATA_STRUCTURES_H

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

namespace utilities {
namespace data_structures {
    using std::vector;
    using std::size_t;

template <typename T>
class Matrix final {

    private:
        vector<vector<T>> array{};

    public:
        Matrix(size_t rows, size_t cols) : array(rows) {
            for (auto& r : array) {
                r.resize(cols);
            }
        }

        Matrix(size_t rows, size_t cols, const T& initial_value) : array(rows) {
            for (auto& row : array) {
                row.resize(cols);
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    array[i][j] = initial_value;
                }
            }
        }

        // Copy constructor
        Matrix(vector<vector<T>> v) : array{v} { }




        constexpr size_t nrows() const noexcept {
            return array.size();
        }

        constexpr size_t ncols() const noexcept {
            if (nrows() > 0) return array[0].size();
            return 0;
        }

        		// test for equality
		bool operator==(const Matrix<T>& rhs) {
			// The matrices are not equal if they don't have the same dimensions.
			if (nrows() != rhs.nrows() && ncols() != rhs.ncols()) {
				return false;
			}

			// Iterate over each element and test for non-equality of the elements at
			// each index. If one pair is found which is not equal then return false.
			for (size_t i = 0; i < nrows(); i++) {
				for (size_t j = 0; j < ncols(); j++) {
					if (array[i][j] != rhs.array[i][j]) {
						return false;
					}
				}
			}
			return true;
		}

		// test for non-equality
		bool operator!=(const Matrix<T>& rhs) {
			return !(*this == rhs);
		}

        // Invoked when the matrix is a Rvalue
		const vector<T>& operator[](size_t row) const {
			if (row < 0 || row >= array.size()) {
				throw std::out_of_range("Invalid row.");
            }
			return array[row];
		}

        // Invoked when the matrix is a Lvalue
		vector<T>& operator[](size_t row) {
			if (row < 0 || row >= array.size()) {
				throw std::out_of_range("Invalid row.");
            }
			return array[row];
		}


}; // class Matrix

// TODO make fancy :)
template <typename T>
std::ostream& operator<<(std::ostream& t, const Matrix<T>& mat) {
    std::cout << std::fixed;
    std::cout.precision(2);
    for(size_t i = 0; i < mat.nrows(); i++) {
        std::cout << "|";
        for(size_t j = 0; j < mat.ncols(); j++) {
            std::cout << " " << std::setw(6) << mat[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    return t;
}


} // namespace data_structures
} // namespace utilities


#endif // _UTILITIES_DATA_STRUCTURES_H