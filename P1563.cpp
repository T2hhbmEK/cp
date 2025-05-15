#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, k;
int dir[maxn];
char job[maxn][20];
int a, s;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> dir[i] >> job[i];
  }
  while (m--) {
    cin >> a >> s;
    if (a ^ dir[k]) {
      k = (k + s) % n;
    } else {
      k = (k - s + n) % n;
    }
  }
  // cout << k << endl;
  cout << job[k] << endl;
  return 0;
}
