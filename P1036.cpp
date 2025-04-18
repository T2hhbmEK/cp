#include <bits/stdc++.h>
using namespace std;
#define N 25
int n, k, x[N], trace[N], cnt;
bool _prime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}
void dfs(int i) {
    // printf("i=%d ", i);
    // for (int j = 1; j < i; ++j) {
    //     printf("%d ", trace[j]);
    // }
    // printf("\n");
    if (i > k) {
        int s = 0;
        for (int j = 1; j <= k; ++j) {
            s += x[trace[j]];
            // printf("%d ", x[trace[j]]);
        }
        // printf("s=%d i=%d\n", s, i);
        if (_prime(s)) {
            cnt++;
        }
        return;
    }
    for (int j = trace[i - 1] + 1; j <= n; ++j) {
        trace[i] = j;
        dfs(i + 1);
        // trace[i] = 0;
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
    }
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}