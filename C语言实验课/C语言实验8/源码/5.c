#include <stdio.h>

void put_max_at_center(int arr[5][5], int m, int n) {
  // 查找最大值
  int max = arr[0][0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] > max) {
        max = arr[i][j];
      }
    }
  }

  // 将最大值放到中心
  arr[m / 2][n / 2] = max;
}

void put_min_at_corner(int arr[5][5], int m, int n) {
  // 查找最小值
  int min = arr[0][0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] < min) {
        min = arr[i][j];
      }
    }
  }

  // 将最小值放到左上角
  arr[0][0] = min;
}

int main() {
  int arr[5][5] = {{0, 1, 2, 3, 4},
                   {5, 6, 7, 8, 9},
                   {10, 11, 12, 13, 14},
                   {15, 16, 17, 18, 19},
                   {20, 21, 22, 23, 24}};
//在这里我定义了一个数组。
  put_max_at_center(arr, 5, 5);
  put_min_at_corner(arr, 5, 5);

  // 打印修改后的数组
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%2d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}
