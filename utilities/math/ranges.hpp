#pragma once

#include <vector>
#include <cmath>
#include <exception>
#include <stdexcept>

#include "../types.hpp"

namespace utilities::math {
    using namespace utilities::types;

    /// DOC
    /// decide to return an empty vector instead of throwing an exception when,
    /// start > end
    std::vector<i32> range(i32 start, i32 end, i32 step_size = 1, bool inclusive = false) noexcept {
        std::vector<i32> sequence;
        i32 step = start;

        auto comparator = inclusive ?
            [](i32 lhs, i32 rhs) { return lhs <= rhs; } :
            [](i32 lhs, i32 rhs) { return lhs < rhs; };

        while (comparator(step, end)) {
            sequence.push_back(step);
            step += step_size;
        }

        return sequence;
    }

    bool is_in_range(i32 element, i32 start, i32 end, i32 step_size = 1, bool inclusive = false) noexcept {
        auto sequence = range(start, end, step_size, inclusive);
        for (const auto x : sequence) {
            if (element == x) {
                return true;
            }
        }

        return false;
    }


    std::vector<f64> arange(f64 start, f64 end, f64 step_size = 1.0) {
        std::vector<f64> sequence;
        f64 step = start;

        while (step < end) {
            sequence.push_back(step);
            step += step_size;
        }

        return sequence;
    }

    std::vector<i64> arange(i64 start, i64 end, i64 step_size = 1) {
        std::vector<i64> sequence;
        i64 step = start;

        while (step < end) {
            sequence.push_back(step);
            step += step_size;
        }

        return sequence;
    }

    // TODO
    /// Return a vector of evenly spaced integers over a specified interval.
    /// Parameters:
    ///     start: f64
    ///         The starting value of the sequence.
    ///     end: f64
    ///         The end value of the sequence, unless @endpoint is set to false. In that case,
    ///         the sequence consists of all but the last num + 1 evenly spaced samples, so that
    ///         stop is excluded. Note that the step size changes when @endpoint is false.
    ///     num: u32, optional
    ///         Number of samples to generate. Default is 50.
    ///     endpoint: bool, optional
    ///         If true, @stop is the last sample. Otherwise, it is not included. Default is true.
    /// Returns:
    ///     sequence: std::vector<f64>
    std::vector<f64> linspace(f64 start, f64 end, u32 num = 50, bool endpoint = false) {
        auto step_size = (end - start) / num;
        std::vector<f64> sequence;


        // ...

        return sequence;
    }
}

/* https://pytorch.org/docs/stable/torch.html */
/* return a 1-D tensor of size (end - start) / step with values from the interval [start, end] */
/* taken with common difference step beginning from start. */
/* arange(start, end, step) */
