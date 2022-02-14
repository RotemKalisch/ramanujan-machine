#pragma once

#include <iostream>
#include <string>

using coef_t = int32_t;

namespace ramanujan {

template <class T>
concept Generator = requires(T a) {
    { a() } -> std::same_as<coef_t>;
    { a.reset() } -> std::same_as<void>;
    { std::cout << a } -> std::same_as<std::ostream&>;
};

} // namespace ramanujan
