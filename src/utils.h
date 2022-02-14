#pragma once

#include <vector>
#include <iostream>

namespace ramanujan {

template <class T>
concept Insertible = requires(T a) { 
    { std::cout << a } -> std::same_as<std::ostream&>;
};

template <Insertible T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "{";
    if (v.size() > 0) {
        for (size_t i = 0; i < v.size() - 1; ++i) {
            os << v[i] << ", ";
        }
        os << v.back();
    }
    os << "}";
    return os;
}

} // namespace ramanujan
