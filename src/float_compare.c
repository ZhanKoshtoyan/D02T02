// Copyright 2026 monabeef

#include <math.h>
#include <stdio.h>

double fun();

int main() {
  double res = fun();

  // Объявляем константу погрешности порядка 1E-6
  const double epsilon = 1e-6;

  // CHANGE THIS IF - AI
  // Функция fabs() возвращает абсолютное значение (модуль) числа.
  // Мы проверяем: если модуль res находится к нулю ближе, чем 0.000001,
  // значит, математически res можно считать равным нулю.
  if (fabs(res - 0.0) < epsilon) {
    printf("OK!");
  }

  return 0;
}

// DO NOT EDIT THE CODE OF THIS FUNCTION - AI
double fun() { return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20)); }

// IT
