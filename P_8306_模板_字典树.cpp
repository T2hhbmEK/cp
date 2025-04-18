#include <bits/stdc++.h>
using namespace std;
#define N 3000005
#define M 62
int t, n, q;
char s[N];
struct Node {
  int cnt;
  int ch[M];
} a[N];
int idx;
int c2i(char x) {
  if (x >= '0' && x <= '9') {
    return x - '0';
  } else if (x >= 'A' && x <= 'Z') {
    return x - 'A' + 10;
  } else {
    // assert(x >= 'a' && x <= 'z');
    return x - 'a' + 36;
  }
}
void add(char* s, int l) {
  int p = 0;  // root
  for (int i = 0; i < l; ++i) {
    int x = c2i(s[i]);
    if (!a[p].ch[x]) {
      a[p].ch[x] = ++idx;
    }
    p = a[p].ch[x];
    a[p].cnt += 1;
  }
}
int find(char* s, int l) {
  int p = 0;
  for (int i = 0; i < l; ++i) {
    int x = c2i(s[i]);
    if (!a[p].ch[x]) {
      return 0;
    }
    p = a[p].ch[x];
  }
  return a[p].cnt;
}
int main() {
  cin >> t;
  for (int i = 0; i < t; ++i) {
    scanf("%d%d", &n, &q);
    for (int j = 0; j < n; ++j) {
      scanf("%s", s);
      add(s, strlen(s));
    }
    for (int j = 0; j < q; ++j) {
      scanf("%s", s);
      printf("%d\n", find(s, strlen(s)));
    }
    memset(a, 0, sizeof(a[0]) * (idx + 1));
    idx = 0;
  }
  return 0;
}