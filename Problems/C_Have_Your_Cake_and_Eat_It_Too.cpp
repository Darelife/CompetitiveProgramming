#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vint b(n);
  vint c(n);
  vcin(a, n);
  vcin(b, n);
  vcin(c, n);
  int k = 0;
  forr(i, n) {
    k += a[i];
  }
  k = (k + 2) / 3;
  debug(k);
  // // we basically need to start making the prefix sum for each of them from a point, and then, as soon as it crosses k, we need to stop
  // // and then give that piece to the user who won....and then, remove that user, and start making the prefix sum for the remaining two from the new point

  // int a1 = 0, b1 = 0, c1 = 0;
  // int adone = 0, bdone = 0, cdone = 0;
  // int la, ra, lb, rb, lc, rc;
  // int start = 0;
  // // first try giving a -> b -> c
  // // then try giving a -> c -> b
  // // then try giving b -> a -> c
  // // then try giving b -> c -> a
  // // then try giving c -> a -> b
  // // then try giving c -> b -> a

  // //* 1
  // forr(i, n) {
  //   a1 += a[i];
  //   if (a1 >= k) {
  //     la = start + 1;
  //     ra = i + 1;
  //     adone = 1;
  //     break;
  //   }
  // }
  // for (int i = ra; i < n; i++) {
  //   b1 += b[i];
  //   if (b1 >= k) {
  //     lb = i + 1;
  //     rb = n;
  //     bdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rb; i < n; i++) {
  //   c1 += c[i];
  //   if (c1 >= k) {
  //     lc = i + 1;
  //     rc = n;
  //     cdone = 1;
  //     break;
  //   }
  // }
  // if (adone && bdone && cdone) {
  //   rc = n;
  //   cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
  //   return;
  // }

  // cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;


  // //* 2
  // a1 = 0, b1 = 0, c1 = 0;
  // adone = 0, bdone = 0, cdone = 0;
  // la, ra, lb, rb, lc, rc;
  // start = 0;

  // forr(i, n) {
  //   a1 += a[i];
  //   if (a1 >= k) {
  //     la = start + 1;
  //     ra = i + 1;
  //     adone = 1;
  //     break;
  //   }
  // }
  // for (int i = ra; i < n; i++) {
  //   c1 += c[i];
  //   if (c1 >= k) {
  //     lc = i + 1;
  //     rc = n;
  //     cdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rc; i < n; i++) {
  //   b1 += b[i];
  //   if (b1 >= k) {
  //     lb = i + 1;
  //     rb = n;
  //     bdone = 1;
  //     break;
  //   }
  // }

  // if (adone && bdone && cdone) {
  //   rb = n;
  //   cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
  //   return;
  // }

  // //* 3
  // a1 = 0, b1 = 0, c1 = 0;
  // adone = 0, bdone = 0, cdone = 0;
  // la, ra, lb, rb, lc, rc;
  // start = 0;

  // forr(i, n) {
  //   b1 += b[i];
  //   if (b1 >= k) {
  //     lb = start + 1;
  //     rb = i + 1;
  //     bdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rb; i < n; i++) {
  //   a1 += a[i];
  //   if (a1 >= k) {
  //     la = i + 1;
  //     ra = n;
  //     adone = 1;
  //     break;
  //   }
  // }
  // for (int i = ra; i < n; i++) {
  //   c1 += c[i];
  //   if (c1 >= k) {
  //     lc = i + 1;
  //     rc = n;
  //     cdone = 1;
  //     break;
  //   }
  // }

  // if (adone && bdone && cdone) {
  //   rc = n;
  //   cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
  //   return;
  // }

  // //* 4
  // a1 = 0, b1 = 0, c1 = 0;
  // adone = 0, bdone = 0, cdone = 0;
  // la, ra, lb, rb, lc, rc;
  // start = 0;

  // forr(i, n) {
  //   b1 += b[i];
  //   if (b1 >= k) {
  //     lb = start + 1;
  //     rb = i + 1;
  //     bdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rb; i < n; i++) {
  //   c1 += c[i];
  //   if (c1 >= k) {
  //     lc = i + 1;
  //     rc = n;
  //     cdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rc; i < n; i++) {
  //   a1 += a[i];
  //   if (a1 >= k) {
  //     la = i + 1;
  //     ra = n;
  //     adone = 1;
  //     break;
  //   }
  // }

  // if (adone && bdone && cdone) {
  //   ra = n;
  //   cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
  //   return;
  // }

  // //* 5
  // a1 = 0, b1 = 0, c1 = 0;
  // adone = 0, bdone = 0, cdone = 0;
  // la, ra, lb, rb, lc, rc;
  // start = 0;

  // forr(i, n) {
  //   c1 += c[i];
  //   if (c1 >= k) {
  //     lc = start + 1;
  //     rc = i + 1;
  //     cdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rc; i < n; i++) {
  //   a1 += a[i];
  //   if (a1 >= k) {
  //     la = i + 1;
  //     ra = n;
  //     adone = 1;
  //     break;
  //   }
  // }
  // for (int i = ra; i < n; i++) {
  //   b1 += b[i];
  //   if (b1 >= k) {
  //     lb = i + 1;
  //     rb = n;
  //     bdone = 1;
  //     break;
  //   }
  // }

  // if (adone && bdone && cdone) {
  //   rb = n;
  //   cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
  //   return;
  // }

  // //* 6
  // a1 = 0, b1 = 0, c1 = 0;
  // adone = 0, bdone = 0, cdone = 0;
  // la, ra, lb, rb, lc, rc;
  // start = 0;

  // forr(i, n) {
  //   c1 += c[i];
  //   if (c1 >= k) {
  //     lc = start + 1;
  //     rc = i + 1;
  //     cdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rc; i < n; i++) {
  //   b1 += b[i];
  //   if (b1 >= k) {
  //     lb = i + 1;
  //     rb = n;
  //     bdone = 1;
  //     break;
  //   }
  // }
  // for (int i = rb; i < n; i++) {
  //   a1 += a[i];
  //   if (a1 >= k) {
  //     la = i + 1;
  //     ra = n;
  //     adone = 1;
  //     break;
  //   }
  // }

  // if (adone && bdone && cdone) {
  //   ra = n;
  //   cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
  //   return;
  // } else {
  //   cout << -1 << endl;
  //   return;
  // }

  int la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
  int a1 = 0, b1 = 0, c1 = 0;
  int adone = 0, bdone = 0, cdone = 0;
  int start = 0;
  // a -> b -> c
  forr(i, n) {
    if (!adone) {
      a1 += a[i];
      if (a1 >= k) {
        la = start + 1;
        ra = i + 1;
        adone = 1;
        start = i + 1;
      }
    } else if (!bdone) {
      b1 += b[i];
      if (b1 >= k) {
        lb = start + 1;
        rb = i + 1;
        bdone = 1;
        start = rb;
      }
    } else {
      c1 += c[i];
      if (c1 >= k) {
        lc = start + 1;
        rc = n;
        cdone = 1;
      }
    }
  }
  if (adone && bdone && cdone) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    // cout << "a -> b -> c" << endl;
    return;
  }

  // a -> c -> b
  a1 = 0, b1 = 0, c1 = 0, adone = 0, bdone = 0, cdone = 0, start = 0, la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
  forr(i, n) {
    if (!adone) {
      a1 += a[i];
      if (a1 >= k) {
        la = start + 1;
        ra = i + 1;
        adone = 1;
        start = i + 1;
      }
    } else if (!cdone) {
      c1 += c[i];
      if (c1 >= k) {
        lc = start + 1;
        rc = i + 1;
        cdone = 1;
        start = rc;
      }
    } else {
      b1 += b[i];
      if (b1 >= k) {
        lb = start + 1;
        rb = n;
        bdone = 1;
      }
    }
  }

  if (adone && bdone && cdone) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    // cout << "a -> c -> b" << endl;
    return;
  }

  // b -> a -> c
  a1 = 0, b1 = 0, c1 = 0, adone = 0, bdone = 0, cdone = 0, start = 0, la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
  forr(i, n) {
    if (!bdone) {
      b1 += b[i];
      if (b1 >= k) {
        lb = start + 1;
        rb = i + 1;
        bdone = 1;
        start = i + 1;
      }
    } else if (!adone) {
      a1 += a[i];
      if (a1 >= k) {
        la = start + 1;
        ra = i + 1;
        adone = 1;
        start = ra;
      }
    } else {
      c1 += c[i];
      if (c1 >= k) {
        lc = start + 1;
        rc = n;
        cdone = 1;
      }
    }
  }

  if (adone && bdone && cdone) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    // cout << "b -> a -> c" << endl;
    return;
  }

  // b -> c -> a
  a1 = 0, b1 = 0, c1 = 0, adone = 0, bdone = 0, cdone = 0, start = 0, la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
  forr(i, n) {
    if (!bdone) {
      b1 += b[i];
      if (b1 >= k) {
        lb = start + 1;
        rb = i + 1;
        bdone = 1;
        start = i + 1;
      }
    } else if (!cdone) {
      c1 += c[i];
      if (c1 >= k) {
        lc = start + 1;
        rc = i + 1;
        cdone = 1;
        start = rc;
      }
    } else {
      a1 += a[i];
      if (a1 >= k) {
        la = start + 1;
        ra = n;
        adone = 1;
      }
    }
  }

  if (adone && bdone && cdone) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    // cout << "b -> c -> a" << endl;
    return;
  }

  // c -> a -> b
  a1 = 0, b1 = 0, c1 = 0, adone = 0, bdone = 0, cdone = 0, start = 0, la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
  forr(i, n) {
    if (!cdone) {
      c1 += c[i];
      if (c1 >= k) {
        lc = start + 1;
        rc = i + 1;
        cdone = 1;
        start = i + 1;
      }
    } else if (!adone) {
      a1 += a[i];
      if (a1 >= k) {
        la = start + 1;
        ra = i + 1;
        adone = 1;
        start = ra;
      }
    } else {
      b1 += b[i];
      if (b1 >= k) {
        lb = start + 1;
        rb = n;
        bdone = 1;
      }
    }
  }

  if (adone && bdone && cdone) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    // cout << "c -> a -> b" << endl;
    return;
  }

  // c -> b -> a
  a1 = 0, b1 = 0, c1 = 0, adone = 0, bdone = 0, cdone = 0, start = 0, la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0;
  forr(i, n) {
    if (!cdone) {
      c1 += c[i];
      if (c1 >= k) {
        lc = start + 1;
        rc = i + 1;
        cdone = 1;
        start = i + 1;
      }
    } else if (!bdone) {
      b1 += b[i];
      if (b1 >= k) {
        lb = start + 1;
        rb = i + 1;
        bdone = 1;
        start = rb;
      }
    } else {
      a1 += a[i];
      if (a1 >= k) {
        la = start + 1;
        ra = n;
        adone = 1;
      }
    }
  }

  if (adone && bdone && cdone) {
    cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    // cout << "c -> b -> a" << endl;
    return;
  }
  cout << -1 << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}