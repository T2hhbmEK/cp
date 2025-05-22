#include <iostream>
#define maxn 110
using namespace std;

int n, a[maxn], k;
int f[maxn];  // f[i]: LIS ends at a[i]
int g[maxn];  // g[i]: LIS reversed

void calcLIS(int f[]) {
  for (int i = 1; i <= n; i++) {
    f[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
  }
}

void flip(int a[]) {
  for (int i = 1, j = n; i < j; i++, j--) {
    swap(a[i], a[j]);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  calcLIS(f);
  flip(a), calcLIS(g), flip(a);
  flip(g);
  for (int i = 1; i <= n; i++) {
    k = max(k, f[i] + g[i] - 1);
  }
  cout << n - k;
  return 0;
}
