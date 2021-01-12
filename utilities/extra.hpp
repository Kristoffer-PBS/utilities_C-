#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <limits>
#include <tuple>

#include "types.hpp"

namespace utilities::extra {
    using namespace utilities::types;

    struct Result {
        u32 value;
        bool ok;
        constexpr static Result error() { return { 0, false }; }
        constexpr static Result success(u32 value) { return { value, true }; }
    };

    // using Result = std::tuple<u32, bool>;

    Result safe_multiplication(u32 a, u32 b) {
        u32 result;
        if (__builtin_mul_overflow(a, b, &result)) {
            // return std::make_tuple(0, false);
            return Result::error();
        }
        // return std::make_tuple(result, true);
        return Result::success(result);
    }

    Result safe_addition(u32 a, u32 b) {
        u32 result;
        if (__builtin_add_overflow(a, b, &result)) {
            // return std::make_tuple(0, false);
            return Result::error();
        }
        // return std::make_tuple(result, true);
        return Result::success(result);
    }
}
