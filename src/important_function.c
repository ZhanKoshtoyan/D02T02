// Copyright 2026 monabeef

#include <math.h>
#include <stdio.h>

int main(void) {
  double x = 0.0;
  char end_char = '\0';

  // 1. Проверка на ввод ТОЛЬКО чисел
  if (scanf("%lf%c", &x, &end_char) != 2 ||
      (end_char != '\n' && end_char != ' ' && end_char != '\t')) {
    printf("n/a");
    return 0;
  }

  // 2. Проверка математических ограничений (Краевые ситуации)
  if (x == 0.0 || (10.0 + x) <= 0.0) {
    printf("n/a");
  } else {
    // 3. Вычисление функции по частям
    double part1 = 7e-3 * pow(x, 4.0);

    double part2 = ((22.8 * cbrt(x) - 1e3) * x + 3.0) / (pow(x, 2.0) / 2.0);

    double part3 = x * pow(10.0 + x, 2.0 / x);

    double y = part1 + part2 - part3 - 1.01;

    // 4. Проверка на ошибки операций с плавающей точкой
    // isnan(y) = функция возвращает «истину» (1),
    // если в процессе расчетов переменная y превратилась в не-число (NaN).
    // isinf(y) = функция возвращает «истину» (1),
    // если результат улетел в бесконечность (Infinity).
    if (isnan(y) || isinf(y)) {
      printf("n/a");
    } else {
      printf("%.1f", y);  // Вывод строго БЕЗ \n в конце
    }
  }

  return 0;
}
