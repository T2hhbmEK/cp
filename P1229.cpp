#include <bits/stdc++.h>
using namespace std;
#define N 30
char s1[N], s2[N];
typedef long long ll;
void p(char *s, int n) {
    while (n) {
        putchar(s[--n]);
    }
}
void p(char *s1, char *s2, int n) {
    p(s1, n);
    printf(" ");
    p(s2, n);
    printf("\n");
}
ll dfs(char *s1, char *s2, int n) {
    if (n == 0) {
        return 1;
    }
    if (s1[0] != s2[n - 1]) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dfs(s1 + 1, s2, i) *
               dfs(s1 + 1 + i, s2 + i, n - 1 - i);
    }
    return ans;
}
int main() {
    cin >> s1 >> s2;
    assert(strlen(s1) == strlen(s2));
    cout << dfs(s1, s2, strlen(s1)) << endl;
    return 0;
}