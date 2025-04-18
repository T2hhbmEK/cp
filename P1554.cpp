#include <bits/stdc++.h>
using namespace std;
int m, n, cnt[10];
void f(int x) {
    while (x > 0) {
        cnt[x % 10] += 1;
        x /= 10;
    }
}
int main() {
    cin >> m >> n;
    for (int i = m; i <= n; ++i) {
        f(i);
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ", cnt[i]);
    }
    printf("\n");
    return 0;
}