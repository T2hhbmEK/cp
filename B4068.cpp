#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int N2 = N * (N - 1) / 2;  // 估计 a[i] 的最大值
int a[N];
int f[N2];  // 统计数组
int main() {
    int n;
    cin >> n;
    a[1] = 1;
    f[a[1]]++;
    for (int k = 2; k <= n; k++) {
        if (a[k - 1] - k > 0 && f[a[k - 1] - k] == 0) {
            a[k] = a[k - 1] - k;
        } else {
            a[k] = a[k - 1] + k;
        }
        f[a[k]]++;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}