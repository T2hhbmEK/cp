#include <bits/stdc++.h>
using namespace std;
#define N 100'000'005
#define qN 6'000'005  // 5761455
int n, p, k, q[qN], cnt;
bool f[N];
void qpush(int x) {
    q[++cnt] = x;
}
void pq() {
    for (int i = 1; i <= cnt; ++i) {
        printf("%d\n", q[i]);
    }
}
bool t(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (!f[i]) {
            qpush(i);
        }
        for (int j = 1; j <= cnt && q[j] * i <= n; ++j) {
            f[q[j] * i] = true;
            if (i % q[j] == 0) {
                break;
            }
        }
    }
    // pq();
    // printf("q[%d]=%d\n", cnt, q[cnt]);
    // return 0;
    cin >> p;
    for (int i = 1; i <= p; ++i) {
        scanf("%d", &k);
        printf("%d\n", q[k]);
    }
    return 0;
}