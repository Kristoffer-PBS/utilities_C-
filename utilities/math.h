#ifndef _UTILITIES_MATH_H
#define _UTILITIES_MATH_H

#include <cstdint>
#include <cmath>

// unique (take a container and filter out unique elements)

/// IDEAS
/// cosine and sine relation formulas
/// chinese remainder theorem

namespace utilities::math {
        const double PI = 3.14159265358979323846;
        const double PI_2 = 1.57079632679489661923;
        const double PI_4 = 0.785398163397448309616;

        uint64_t factorial(uint64_t n) {
            return n;
        } 

        long fibonacci(long n) {
            return n;
        }

        long tribonacci(long n) {
            return n;
        }

        long gcd(uint64_t a, uint64_t b) noexcept {
            return 0;
        }

        long lcm(uint64_t a, uint64_t b) noexcept {
            return 2;
        }
        
        // TODO 
        constexpr double hypotenuse(double a, double b) noexcept {
            // handle if input is negative

        }
        
        /// Convert from radians to degrees
        /// @param radian: double - the radian to be converted.
        /// return: double - the input radian converted to a degree.
        constexpr double rad2deg(double radian) {
            return radian * 180 / M_PI;
        }
        
        /// convert from degrees to radians
        /// @param degree: double - a degree expressed as a double.
        /// return: double - the input degree converted to a radian.
        constexpr double deg2rad(double degree) noexcept {
            return degree * M_PI / 180;
        }

} // namespace utilities::math

#endif // _UTILITIES_MATH_H
