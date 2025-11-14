#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i:a) cin >> i;
   cout << n/2 << endl;
   for (int i = 0; i<n; i++) {
    cout << (abs(a[i]+n/2-1))%n+1 << " ";
   }
}