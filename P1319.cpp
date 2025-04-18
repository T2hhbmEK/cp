#include <bits/stdc++.h>
using namespace std;
#define N 205
int n, x, i, a;
int main() {
    cin >> n;
    while (i < n * n) {
        scanf("%d", &x);
        for (int j = 1; j <= x; ++j) {
            printf("%d", a);
            if (++i % n == 0) {
                printf("\n");
            }
        }
        a = !a;
    }
    return 0;
}