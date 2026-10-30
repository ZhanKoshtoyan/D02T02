# D02T02. Первая программа на языке C

Учебный проект школы 21 (School 21 / Ecole 42), посвящённый базовым операциям на языке C: ввод/вывод, арифметика, работа с числами с плавающей точкой, округлением и проверкой ввода.

В репозитории собраны отдельные небольшие программы, каждая из которых решает свою задачу из проекта D02T02. Все программы читают данные из `stdin` и выводят результат в `stdout`.

## Стек и требования

- Язык: **C** (стандарт **C11**)
- Компилятор: **gcc**
- Флаги сборки: `-Wall -Wextra -Werror`
- Стиль кода: **Google C++ Style Guide**
- Вывод программ **не должен заканчиваться переводом строки** (кроме случаев, где это явно требуется заданием)
- Для большинства программ разрешён только `<stdio.h>`
- Для `important_function.c` и `float_compare.c` дополнительно разрешён `<math.h>`

## Структура репозитория

```text
.
├── README.md
└── src/
    ├── hello.c
    ├── named_hello.c
    ├── arithmetic.c
    ├── max.c
    ├── important_function.c
    ├── float_compare.c
    └── crack.c
```

Каждый файл в `src/` — самостоятельная программа с функцией `main`.

## Сборка

Каждую программу можно собрать отдельно. Пример для `hello.c`:

```bash
gcc -Wall -Wextra -Werror -std=c11 src/hello.c -o hello
./hello
```

Для программ, использующих `<math.h>` (`important_function.c`, `float_compare.c`), добавьте `-lm`:

```bash
gcc -Wall -Wextra -Werror -std=c11 src/important_function.c -o important_function -lm
gcc -Wall -Wextra -Werror -std=c11 src/float_compare.c -o float_compare -lm
```

## Программы

### 1. `hello.c` — Приветствие

Выводит строку `Hello, AI!`.

- **Вход:** нет
- **Выход:** `Hello, AI!`
- **Библиотеки:** `<stdio.h>`

```bash
gcc -Wall -Wextra -Werror -std=c11 src/hello.c -o hello
./hello
# Hello, AI!
```

### 2. `named_hello.c` — Приветствие по имени

Принимает целое число `name` и выводит `Hello, <name>!`.

- **Вход:** целое число
- **Выход:** `Hello, <name>!`
- **Ошибка ввода:** `n/a`
- **Библиотеки:** `<stdio.h>`

| Вход  | Выход         |
|-------|---------------|
| `123` | `Hello, 123!` |

```bash
gcc -Wall -Wextra -Werror -std=c11 src/named_hello.c -o named_hello
echo 123 | ./named_hello
# Hello, 123!
```

### 3. `arithmetic.c` — Арифметика

Принимает два целых числа и выводит через пробел: сумму, разность, произведение и целую часть от деления.

- **Вход:** два целых числа
- **Выход:** `sum diff mul div` (через пробел, без завершающего пробела)
- **Деление на ноль:** на месте частного выводится `n/a`
- **Ошибка ввода:** `n/a`
- **Библиотеки:** `<stdio.h>`

| Вход  | Выход       |
|-------|-------------|
| `8 2` | `10 6 16 4` |
| `1 0` | `1 1 0 n/a` |
| `3 2` | `5 1 6 1`   |

```bash
gcc -Wall -Wextra -Werror -std=c11 src/arithmetic.c -o arithmetic
echo "8 2" | ./arithmetic
# 10 6 16 4
```

### 4. `max.c` — Максимум из двух чисел

Принимает два целых числа и выводит наибольшее из них. Поиск максимума оформлен отдельной функцией.

- **Вход:** два целых числа
- **Выход:** наибольшее число
- **Ошибка ввода:** `n/a`
- **Библиотеки:** `<stdio.h>`

| Вход        | Выход |
|-------------|-------|
| `3 2`       | `3`   |
| `12.3 10`   | `n/a` |

```bash
gcc -Wall -Wextra -Werror -std=c11 src/max.c -o max
echo "3 2" | ./max
# 3
```

### 5. `important_function.c` — Сложные вычисления

Принимает одно число `x` с плавающей точкой и вычисляет:

```text
y = 7e-3 * x^4 + ((22.8 * x^(1/3) - 1e3) * x + 3) / (x^2 / 2) - x * (10 + x)^(2/x) - 1.01
```

Результат выводится с одной цифрой после запятой.

- **Вход:** одно число с плавающей точкой
- **Выход:** значение `y` с точностью до одного знака после запятой
- **Ошибки:** деление на ноль, `NaN`, `Infinity`, некорректный ввод → `n/a`
- **Библиотеки:** `<stdio.h>`, `<math.h>`

| Вход | Выход    |
|------|----------|
| `1`  | `-2070.4` |

```bash
gcc -Wall -Wextra -Werror -std=c11 src/important_function.c -o important_function -lm
echo 1 | ./important_function
# -2070.4
```

### 6. `float_compare.c` — Сравнение с плавающей точкой

Демонстрирует корректное сравнение числа с плавающей точкой с нулём с использованием эпсилон-погрешности (`1e-6`). В результате работы должна выводиться строка `OK!`.

- **Вход:** нет
- **Выход:** `OK!`
- **Библиотеки:** `<stdio.h>`, `<math.h>`

```bash
gcc -Wall -Wextra -Werror -std=c11 src/float_compare.c -o float_compare -lm
./float_compare
# OK!
```

### 7. `crack.c` — Взлом замка

Принимает координаты точки `(x, y)` с плавающей точкой и определяет, находится ли точка внутри окружности `x^2 + y^2 = 25`.

- **Вход:** два числа с плавающей точкой
- **Выход:** `GOTCHA`, если точка внутри окружности, иначе `MISS`
- **Ошибка ввода:** `n/a`
- **Библиотеки:** `<stdio.h>`

| Вход       | Выход    |
|------------|----------|
| `1.5 1.5`  | `GOTCHA` |

```bash
gcc -Wall -Wextra -Werror -std=c11 src/crack.c -o crack
echo "1.5 1.5" | ./crack
# GOTCHA
```

## Пример быстрой проверки всех программ

```bash
# hello
gcc -Wall -Wextra -Werror -std=c11 src/hello.c -o hello && ./hello

# named_hello
gcc -Wall -Wextra -Werror -std=c11 src/named_hello.c -o named_hello && echo 123 | ./named_hello

# arithmetic
gcc -Wall -Wextra -Werror -std=c11 src/arithmetic.c -o arithmetic && echo "8 2" | ./arithmetic

# max
gcc -Wall -Wextra -Werror -std=c11 src/max.c -o max && echo "3 2" | ./max

# important_function
gcc -Wall -Wextra -Werror -std=c11 src/important_function.c -o important_function -lm && echo 1 | ./important_function

# float_compare
gcc -Wall -Wextra -Werror -std=c11 src/float_compare.c -o float_compare -lm && ./float_compare

# crack
gcc -Wall -Wextra -Werror -std=c11 src/crack.c -o crack && echo "1.5 1.5" | ./crack
```

## Примечания

- Проект выполнен в рамках учебной программы школы 21 (D02T02).
- В репозитории намеренно отсутствуют объектные и исполняемые файлы — только исходный код.
- Все программы соответствуют требованиям по стилю и флагам компиляции, указанным в задании.
- Вывод программ не содержит завершающего перевода строки, если это не требуется условием.

## Автор

**monabeef**