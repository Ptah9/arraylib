// Вариант 17. Суммы чеков.
#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    int receipts[] = {
        850, 1240, 430, 2190,
        760, 1580, 990, 3100
    };

    const std::size_t n = sizeof(receipts) / sizeof(receipts[0]);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Суммы чеков (" << n << " шт.): ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << receipts[i] << (i + 1 < n ? ' ' : '\n');
    }
    std::cout << '\n';

    std::cout << "Общая сумма покупок: "
              << arr_sum(receipts, n) << " руб.\n";
    std::cout << "Самый дорогой чек:   "
              << arr_max(receipts, n) << " руб.\n";
    std::cout << "Самый дешёвый чек:   "
              << arr_min(receipts, n) << " руб.\n";
    std::cout << "Средняя сумма чека:  "
              << arr_average(receipts, n) << " руб.\n";
    std::cout << "Медиана чеков:       "
              << arr_median(receipts, n) << " руб.\n";
    std::cout << '\n';

    // Медиана не должна менять исходный массив — сверяем порядок.
    const int original[] = {850, 1240, 430, 2190,
                            760, 1580, 990, 3100};
    bool same = true;
    for (std::size_t i = 0; i < n; ++i) {
        if (receipts[i] != original[i]) {
            same = false;
        }
    }
    std::cout << "Исходный массив после расчёта медианы: "
              << (same ? "не изменён" : "ИЗМЕНЁН") << '\n';

    return 0;
}
