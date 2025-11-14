#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i:a) cin >> i;
   
   for (int i = 0; i<n; i++) {
    cout << i+1 <<" " <<  a[i] << endl;
   }
}