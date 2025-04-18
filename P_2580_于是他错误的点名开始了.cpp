#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int n, nxt[N][26], cnt, m;
bool vis[N], ok[N];
int main() {
  cin >> n;
  while (n > 0) {
    char s[100];
    scanf("%s", s);
    int p = 0;
    for (int i = 0; i < strlen(s); ++i) {
      int j = s[i] - 'a';
      if (!nxt[p][j]) {
        nxt[p][j] = ++cnt;
      }
      p = nxt[p][j];
    }
    ok[p] = true;
    --n;
  }
  cin >> m;
  while (m > 0) {
    char s[100];
    scanf("%s", s);
    int p = 0;
    for (int i = 0; i < strlen(s); ++i) {
      int j = s[i] - 'a';
      if (!nxt[p][j]) {
        break;
      }
      p = nxt[p][j];
    }
    if (!ok[p]) {
      printf("WRONG\n");
    } else {
      if (!vis[p]) {
        printf("OK\n");
        vis[p] = true;
      } else {
        printf("REPEAT\n");
      }
    }
    --m;
  }
  return 0;
}