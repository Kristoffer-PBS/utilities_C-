
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

#include "../../utilities/string/levenshtein_distance.h"

using utilities::string::levenshtein_distance;


void test(std::string_view a, std::string_view b, unsigned int expected) {
    int res = levenshtein_distance(a, b);
    std::cout << "lev(" << a << "," << b << ") = " << res << "\n";
    std::cout << "expected value = " << expected << "\n";
    assert(res == expected);
}


int main() {

    std::cout << "MIN " << std::min({2, 2, 3}) << std::endl;

    test("saturday", "sunday", 3);
    test("king", "king", 0);
    test("kitten", "sitting", 3);
    test("peter", "", 5);
    test("", "Denmark", 7);
    test("book", "back", 2);
    test("ephrem", "benyam", 5);
    test("benyam", "ephrem", 5);
    test("Saturday", "Sundays", 4);
    /* test("australia", "cement", 9); */
    test("adkasdhaæhsdæjakdhjakhsjh", "askdjaklsdjaksldjaslkjadsjalsædjkaslkdj", 25);
    /* test("kristoffer", "newyork", 9); */




    return 0;
}
