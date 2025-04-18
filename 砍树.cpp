#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, m, h[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    int l = 0, r = 1e9 - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += max(0, h[i] - mid);
        }
        if (sum < m) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
}
