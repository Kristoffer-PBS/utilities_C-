#pragma once

#include <cmath>


namespace utilities::math {


    /**
    @brief https://easings.net/#easeInSine

    @param x The variable x represents the absolute progrss of the animation
    in the bounds of 0 (beginning of the animation) and 1(end of animations)
    @return [TODO:description]
    */
    auto ease_in_size(double x) -> double {
        return 1 - std::cos((x * M_PI) / 2);
    }

    auto foo() -> int {

    int abac(double foo, std::string s) {
        return 2;
    }

}


} // namespace utilities::math
