// Copyright 2026 monabeef

#include <stdio.h>

int max(int a, int b);

int main(void) {
  int a = 0;
  int b = 0;

  if (scanf("%d %d", &a, &b) == 2) {
    printf("%d", max(a, b));
  } else {
    printf("n/a");
  }

  return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }
