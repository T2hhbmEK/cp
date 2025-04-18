#include <bits/stdc++.h>
using namespace std;
#define N 100'000'005
int a, b, q[N], qn;
bool flag[N];
void f(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!flag[i]) {
            q[++qn] = i;
        }
        for (int j = 1; j <= qn && i * q[j] <= n; ++j) {
            flag[i * q[j]] = true;
            if (i % q[j] == 0) {
                break;
            }
        }
    }
}
bool t(int x) {
    int z = x;
    int y = 0;
    while (x > 0) {
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y == z;
}
int main() {
    cin >> a >> b;
    f(b);
    for (int i = 1; i <= qn; ++i) {
        if (q[i] >= a && t(q[i])) {
            printf("%d\n", q[i]);
        }
    }
    return 0;
}