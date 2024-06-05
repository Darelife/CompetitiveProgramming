#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  int hours;
  int mins;
  for (int i = 0; i < t; i++) {

    scanf("%d:%d", &hours, &mins);
    if (hours == 0) {
      hours = 12;
      printf("%02d:%02d AM\n", hours, mins);
    } else if (hours < 12) {
      printf("%02d:%02d AM\n", hours, mins);
    } else if (hours == 12) {
      printf("%02d:%02d PM\n", hours, mins);
    } else {
      hours = hours - 12;
      printf("%02d:%02d PM\n", hours, mins);
    }

  }

  return 0;
}
