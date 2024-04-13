#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_perfect_square(int number) {
  int root = (int)sqrt(number);
  return number == root * root;
}

int main(int argc, char *argv[]) {
  // Проверяем, есть ли аргументы командной строки
  if (argc < 2) {
    printf("Usage: %s <size_of_array>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int *array = (int *)malloc(n * sizeof(int));
  if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  // Инициализируем генератор случайных чисел
  srand(time(NULL));

  // Заполняем массив и выводим числа, не являющиеся полными квадратами
  printf("Numbers that are not perfect squares:\n");
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 100 + 1; // Генерация чисел от 1 до 100
    if (!is_perfect_square(array[i])) {
      printf("%d ", array[i]);
    }
  }
  printf("\n");

  // Освобождаем выделенную память
  free(array);

  return 0;
}