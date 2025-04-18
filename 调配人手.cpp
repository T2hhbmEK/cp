#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
int n, q, a[N], sub[N], bg, ed;
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        sub[i] = a[i] - a[i - 1];
    }
    while (q--) {
        cin >> bg >> ed;
        sub[bg] += 1;
        sub[ed + 1] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + sub[i];
        cout << a[i] << " ";
    }
    return 0;
}