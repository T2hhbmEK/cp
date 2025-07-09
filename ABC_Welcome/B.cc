#include <bits/stdc++.h>
using namespace std;
/*
merge sort
f(n) = f(n/2)+f(n-n/2)+n-1;
1
1<2
1<2<3
1 2<3<4
1 2<3<4<5
 */
#define MAXN 32
int f(int n) {
  if (n <= 1) return 0;
  return f(n / 2) + f(n - (n / 2)) + n - 1;
}
bool cmp(char a, char b) {
  cout << "? " << a << " " << b << '\n';
  cout.flush();
  char c;
  cin >> c;
  return c == '<';
}
char a[MAXN];
int n, q;
void msort(char a[], int L, int R) {
  char t[MAXN];
  if (L + 1 >= R) return;
  int M = L + ((R - L) >> 1);
  msort(a, L, M), msort(a, M, R);
  merge(a + L, a + M, a + M, a + R, t + L, cmp);
  for (int i = L; i < R; ++i) a[i] = t[i];
}
void dsort5(char a[]) {
  char t[MAXN] = {};
  if (!cmp(a[0], a[1])) swap(a[0], a[1]);                    // A < B
  if (!cmp(a[2], a[3])) swap(a[2], a[3]);                    // C < D
  if (!cmp(a[0], a[2])) swap(a[0], a[2]), swap(a[1], a[3]);  // A < C
  /*
   * A < B
   *   < C < D
   */
  t[0] = a[0], t[1] = a[2], t[2] = a[3];  // A C D
  // for (int i = 0; i < 5; ++i) cerr << t[i] << " \n"[i == 4];
  //  A C D
  // 0 1 2 3
  // (0, 3) -> (0, 1) (2, 3) -> (0, 0) (1, 1) (2, 2) (3, 3)
  function<void(int, int, int)> binsert = [&](int i, int j, char x) {
    if (i == j) {
      t[i] = x;
      return;
    }
    int m = (i + j) / 2;
    if (cmp(x, t[m])) {
      for (int y = j; y > m; --y) t[y] = t[y - 1];
      binsert(i, m, x);
    } else {
      binsert(m + 1, j, x);
    }
  };
  binsert(0, 3, a[4]);  // ACD<-E
  // for (int i = 0; i < 5; ++i) cerr << t[i] << " \n"[i == 4];
  binsert(1, 4, a[1]);  // A CDE<-B
  // for (int i = 0; i < 5; ++i) cerr << t[i] << " \n"[i == 4];
  for (int i = 0; i < 5; ++i) a[i] = t[i];
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) a[i] = static_cast<char>('A' + i);
  if (n == 5) {
    dsort5(a);
  } else {
    msort(a, 0, n);
  }
  cout << "! " << a << '\n';
  cout.flush();
  return 0;
}
