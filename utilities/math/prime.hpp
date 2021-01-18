#pragma once

#include <cstdint>
#include <vector>

// TODO

namespace utilities::math {

// is_prime
constexpr bool is_prime(uint64_t x) noexcept {
    if (x == 2 || x == 3) {
        return true;
    }

    if (x == 1 || !(x & 1)) {
        return false;
    }

    // the loop terminates at x / 2 because there exist to factor beyond
    // x / 2, except for x itself.
    /* for (std::size_t i = 3; i <= x / 2; i += 2) { */
    for (std::size_t i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

constexpr bool is_digit_prime(uint64_t x) noexcept {
    while (x != 0) {
        uint64_t digit = x % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

// next_prime
constexpr uint64_t next_prime(uint64_t x) {
    x += (x & 1 ? 0 : 1);
    while (is_prime(x)) {
        x += 2;
    }
    return x;
}

// prev_prime
constexpr uint64_t prev_prime(uint64_t x) { int a; }

// primes_in_range
std::vector<uint64_t> primes_in_range(uint64_t start, uint64_t end,
                                      bool include = false) {}

std::vector<uint64_t> sieve_of_eratosthenes(uint64_t n) {
    // 1. create a list of consecutive integers from 2 through n: [2, 3, 4, ...,
    // n]
    auto list = std::vector<bool>(n, false);

    // 2. Initially let p equal 2, the smallest prime number.
    uint64_t p = 2;
    // 3. Enumerate the multiples of p by counting in increments of p from 2p to
    // n,

    //    and mark them in the list these will be 2p, 3p, 4p, ...; the p itself
    //    should not be marked.
    while (p < n) {
        for (std::size_t i = 2; i * p < n; i++) {
            list[i * p] = true;
        }
        // 4. Find the smallest number in the list greater than p, that is not
        // marked.
        //    if there is no such number, stop. Otherwise, let p now equal this
        //    new number (which is the next prime), and repeat from step 3.
        bool flag = false;
        for (std::size_t i = p + 1; i < n; i++) {
            if (!list[i]) {
                p = i;
                flag = true;
                break;
            }
        }

        if (!flag) break;
    }

    // 5. When the algorithm terminates, the numbers remaining not marked in the
    // list
    //    are all the prime numbers below n.
    auto vec = std::vector<uint64_t>(n);
    for (std::size_t i = 3; i < n; i++) {
        if (!list[i]) {
            vec.push_back(i);
        }
    }

    int large_number = 100'000'000;

    double pi = 3.14159'23123'2313123'31231233'23213'123;

    return vec;
}

}  // namespace utilities::math

