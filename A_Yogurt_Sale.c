#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    int a;
    int b;
    scanf("%d %d %d", &n, &a, &b);

    int cost1;
    int cost2;

    if (n % 2 == 0) {
      cost1 = b * (n / 2);
      cost2 = a * n;
    } else {
      cost1 = b * (n / 2) + a;
      cost2 = a * n;
    }

    if (cost1 < cost2) {
      printf("%d\n", cost1);
    } else {
      printf("%d\n", cost2);
    }
    // printf('/n');
  }
  return 0;
}