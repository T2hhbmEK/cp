#include <bits/stdc++.h>
using namespace std;
#define N 10
char a[N], b[N];
void dfs(char* a, char* b, int n) {
    if (n == 0) return;
    putchar(b[n - 1]);
    if (n == 1) return;
    int i = 0;
    while (a[i] != b[n - 1]) ++i;
    dfs(a, b, i);
    dfs(a + i + 1, b + i, n - 1 - i);
}
int main() {
    cin >> a >> b;
    dfs(a, b, strlen(a));
    cout << endl;
    return 0;
}