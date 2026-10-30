// Copyright 2026 monabeef

#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main(void) {
  int a = 0;
  int b = 0;

  if (scanf("%d %d", &a, &b) == 2) {
    if (b == 0) {
      printf("%d %d %d n/a", sum(a, b), diff(a, b), mul(a, b));
    } else {
      printf("%d %d %d %d", sum(a, b), diff(a, b), mul(a, b), div(a, b));
    }
  } else {
    printf("n/a");
  }

  return 0;
}

int sum(int a, int b) { return a + b; }

int diff(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int div(int a, int b) { return a / b; }
