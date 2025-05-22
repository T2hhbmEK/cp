#include <bits/stdc++.h>
#define maxn 101
#define maxm 100001
#define maxw 40001
#define chmax(a, b) a = max(a, b)
using namespace std;

int n, W, v[maxn], w[maxn], m[maxn];
int f[maxw];
int main() {
  cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> m[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 1, s = 0; s < m[i]; s += k, k <<= 1) {
      if (s + k > m[i]) k = m[i] - s;
      for (int j = W; j >= w[i] * k; j--) {
        chmax(f[j], f[j - w[i] * k] + v[i] * k);
      }
    }
  }
  cout << f[W];
  return 0;
}
