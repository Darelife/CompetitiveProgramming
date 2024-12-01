#include<bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int num = 0;num < t;num++) {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0;i < n;i++) {
      cin >> arr[i];
    }
    long long a = 2;
    while (a > 0) {
      bool x = true;
      for (int i = 0;i < n - 1;i++) {
        if (arr[i] % a != arr[i + 1] % a) {
          x = false;
          break;
        }
      }
      if (x == false) {
        cout << a << endl;
        break;
      } else {
        a = a * 2;
      }
    }
  }
  return 0;
}