#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int b[N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    b[a]++;
  }
  for (int i = 1; i <= 1000; i++) {
    b[i] = b[i - 1] + b[i] * i;
  }
  int ans = 0;
  for (int i = k + 1; i <= 1001; i++) {
    ans = max(ans, b[i] - b[i - k - 1]);
  }
  cout << ans;
  return 0;
}