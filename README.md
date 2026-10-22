# arraylib

Кроссплатформенная динамическая библиотека операций над массивами целых чисел
и программа-калькулятор, использующая её.

Лабораторная работа № 2 по дисциплине «Алгоритмизация и программирование»,
МГТУ им. Н.Э. Баумана, кафедра ИУ5. Вариант 17 — «Суммы чеков».

## Структура проекта

```
arraylib/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── main.cpp                  демонстрационная программа app
├── include/
│   └── arraylib.h            интерфейс библиотеки и макрос экспорта
├── src/
│   └── arraylib.cpp          реализация функций
├── tests/
│   ├── test_unit.cpp         модульные тесты (assert)
│   └── test_integration.cpp  интеграционные тесты
├── examples/
│   └── variant_17.cpp        прикладная задача по варианту
└── .github/
    └── workflows/
        └── ci.yml            сборка и тесты на GitHub Actions
```

## Функции библиотеки

| Функция | Результат |
|---|---|
| `arr_sum` | сумма элементов, `int` |
| `arr_max` | максимальный элемент, `int` |
| `arr_min` | минимальный элемент, `int` |
| `arr_average` | среднее арифметическое, `double` |
| `arr_count_positive` | количество элементов > 0 |
| `arr_count_negative` | количество элементов < 0 |
| `arr_count_zero` | количество элементов == 0 |
| `arr_product` | произведение элементов, `int` |
| `arr_median` | медиана, `double`, исходный массив не меняется |

Размер массива передаётся отдельным параметром `std::size_t n`, массивы не пустые
(`n > 0`). При переполнении `int` поведение `arr_sum` и `arr_product` не определено.

## Сборка

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

Артефакты: `build/libarraylib.so`, `build/app`, `build/variant_17`,
`build/test_unit`, `build/test_integration`.

## Запуск

```bash
./build/app            # демонстрация всех функций библиотеки
./build/variant_17     # вариант 17: суммы чеков
```

Библиотека ищется рядом с исполняемым файлом благодаря `BUILD_RPATH "$ORIGIN"`.

## Тесты

```bash
cd build && ctest --output-on-failure
```

## Ручная сборка без CMake

Статическая библиотека:

```bash
g++ -c src/arraylib.cpp -Iinclude -o arraylib.o
ar rcs libarraylib.a arraylib.o
g++ main.cpp -Iinclude -L. -larraylib -o app
```

Динамическая библиотека:

```bash
g++ -fPIC -c src/arraylib.cpp -Iinclude -o arraylib_pic.o
g++ -shared -o libarraylib.so arraylib_pic.o
g++ main.cpp -Iinclude -L. -larraylib -o app
LD_LIBRARY_PATH=. ./app
```
