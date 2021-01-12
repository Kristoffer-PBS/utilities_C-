#include <cassert>
#include <iostream>
#include <vector>

#include "../../utilities/types.hpp"
#include "../../utilities/math/ranges.hpp"
#include "../../utilities/terminal.hpp"

int main() {
    using utilities::math::range;
    using namespace utilities::types;

    assert(range(0, 10) == (std::vector<i32> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }));
    assert(range(5, 2) == std::vector<i32> { } );
    assert(range(0, 5, 1, true) == (std::vector<i32> {0, 1, 2, 3, 4, 5}));
    assert(range(-7, -3) == (std::vector<i32> { -7, -6, -5, -4 }));
    assert(range(0, 10, 2) == (std::vector<i32> { 0, 2, 4, 6, 8 }));
    assert(range(0, 10, 2, true) == (std::vector<i32> { 0, 2, 4, 6, 8, 10 }));

    std::cout << utilities::terminal::green("all test passed :D") << std::endl;

    return 0;
}
