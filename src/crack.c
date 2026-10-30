// Copyright 2026 monabeef

#include <stdio.h>

int main(void) {
  double a = 0.0;
  double b = 0.0;
  char end_char = '\0';

  // 1. Проверка на ввод ТОЛЬКО чисел
  if (scanf("%lf %lf%c", &a, &b, &end_char) != 3 ||
      (end_char != '\n' && end_char != ' ' && end_char != '\t')) {
    printf("n/a");
    return 0;
  }

  if (a * a + b * b <= 25.0) {
    printf("GOTCHA");
  } else {
    printf("MISS");
  }

  return 0;
}
