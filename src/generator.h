#pragma once

using coef_t = int32_t;

template <class T>
concept Generator = requires(T a) {
    { a() } -> std::same_as<coef_t>;
    { a.reset() } -> std::same_as<void>;
};
