#include <bits/stdc++.h>
#define maxn 10'000'010
#define int long long
using namespace std;

int n, k;

signed main() {
  cin >> n >> k;
  cout << n * (n - 1) / 2 - k;
  return 0;
}
