
#include <thread>
#include <chrono>
#include <iostream>

#include "utilities.h"

int main() {
    cout << "foo" << endl;


    print_at_cursor("Kristoffer", 30, 57);

    std::this_thread::sleep_for(2s);


    return 0;
}