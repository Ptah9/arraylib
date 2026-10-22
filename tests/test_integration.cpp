#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    int data[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    // Случай 1: сумма и максимум согласованы
    assert(arr_sum(data, n) == 45);
    assert(arr_max(data, n) == 9);

    // Случай 2: среднее лежит между минимумом и максимумом
    double avg = arr_average(data, n);
    assert(avg >= static_cast<double>(arr_min(data, n)));
    assert(avg <= static_cast<double>(arr_max(data, n)));

    // Случай 3: счётчики в сумме дают размер массива
    const int counters = arr_count_positive(data, n)
                       + arr_count_negative(data, n)
                       + arr_count_zero(data, n);
    assert(counters == static_cast<int>(n));

    // Случай 4: медиана отсортированного массива
    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    assert(close(arr_median(sorted, 7), 4.0));

    // Случай 5: медиана и среднее не зависят от порядка элементов
    int permuted[] = {4, 6, 2, 8, 1, 9, 3, 5, 7};
    assert(close(arr_median(permuted, n), arr_median(data, n)));
    assert(close(arr_average(permuted, n), avg));

    // Случай 6: произведение и сумма на массиве из единиц
    int ones[] = {1, 1, 1, 1, 1};
    assert(arr_product(ones, 5) == 1);
    assert(arr_sum(ones, 5) == 5);

    std::cout << "[integration] All tests passed\n";
    return 0;
}
