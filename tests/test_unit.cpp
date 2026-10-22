#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    // Массив с положительными, отрицательными и нулём
    int a[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(a) / sizeof(a[0]);

    assert(arr_sum(a, n) == 7);
    assert(arr_max(a, n) == 8);
    assert(arr_min(a, n) == -5);
    assert(arr_count_positive(a, n) == 3);
    assert(arr_count_negative(a, n) == 2);
    assert(arr_count_zero(a, n) == 1);
    assert(arr_product(a, n) == 0);  // в массиве есть ноль

    assert(close(arr_average(a, n), 7.0 / 6.0));

    // Произведение на маленьких значениях (без переполнения)
    int d[] = {1, 2, 3, 4};
    assert(arr_product(d, 4) == 24);

    // Массив из одного элемента
    int one[] = {42};
    assert(arr_sum(one, 1) == 42);
    assert(arr_max(one, 1) == 42);
    assert(arr_min(one, 1) == 42);

    std::cout << "[unit] All tests passed\n";
    return 0;
}
