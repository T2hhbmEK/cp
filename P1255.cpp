#include <bits/stdc++.h>
using namespace std;

int n;
int dp[3][1050];

void _print(int* x) {
    for (int i = x[0]; i >= 1; --i) {
        printf("%d", x[i]);
    }
    printf("\n");
}

void _add(int* x, int* y, int* z) {
    z[0] = max(x[0], y[0]);
    for (int i = x[0] + 1; i <= z[0]; ++i) {
        x[i] = 0;
    }
    for (int i = y[0] + 1; i <= z[0]; ++i) {
        y[i] = 0;
    }
    z[1] = 0;
    for (int i = 1; i <= z[0]; ++i) {
        z[i] += x[i] + y[i];
        z[i + 1] = z[i] / 10;
        z[i] %= 10;
    }
    if (z[z[0] + 1] > 0) {
        z[0]++;
    }
}

int main() {
    scanf("%d", &n);
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        _add(dp[(i - 1) % 3], dp[(i - 2) % 3], dp[i % 3]);
    }
    _print(dp[n % 3]);
    return 0;
}