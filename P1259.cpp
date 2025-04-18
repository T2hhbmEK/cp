#include <bits/stdc++.h>
using namespace std;
#define N 210
int n;
char dp[N][N];

void _print(int n) {
    for (int i = 2 * n - 3; i >= 0; --i) {
        printf("%s\n", dp[i]);
    }
}

int main() {
    scanf("%d", &n);
    strcpy(dp[5], "oooo****--");
    strcpy(dp[4], "ooo--***o*");
    strcpy(dp[3], "ooo*o**--*");
    strcpy(dp[2], "o--*o**oo*");
    strcpy(dp[1], "o*o*o*--o*");
    strcpy(dp[0], "--o*o*o*o*");
    // _print(4);
    for (int i = 0; i <= 5; ++i) {
        for (int j = 10; j <= 2 * n; j += 2) {
            dp[i][j] = 'o';
            dp[i][j + 1] = '*';
        }
    }
    for (int i = 5; i <= n; ++i) {
        int l = 2 * i - 3;
        strcpy(dp[l - 1], dp[l - 2]);
        swap(dp[l - 1][i - 1], dp[l - 1][2 * (i - 1)]);
        swap(dp[l - 1][i], dp[l - 1][2 * (i - 1) + 1]);
        strcpy(dp[l], dp[l - 1]);
        swap(dp[l][i - 1], dp[l][2 * i]);
        swap(dp[l][i], dp[l][2 * i + 1]);
    }
    _print(n);
    return 0;
}