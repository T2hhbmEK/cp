#include <bits/stdc++.h>
using namespace std;
#define N 100000000
int k, m, n, f[3];
int main() {
    scanf("%d", &k);
    f[0] = 1;
    f[1] = 1;
    int i = 1;
    while (f[i % 3] <= k) {
        f[(i + 1) % 3] = f[i % 3] + f[(i - 1) % 3];
        // printf("%d %d %d %d\n", i, f[(i + 1) % 3], f[i % 3], f[(i - 1) % 3]);
        i++;
    }
    m = f[(i - 2) % 3];
    n = f[(i - 1) % 3];
    printf("m=%d\nn=%d\n", m, n);
    return 0;
}