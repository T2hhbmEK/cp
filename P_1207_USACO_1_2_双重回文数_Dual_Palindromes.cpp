#include <bits/stdc++.h>
using namespace std;
int n, s;
int flip(int x, int b) {
    int y = 0;
    while (x) {
        y = y * b + x % b;
        x /= b;
    }
    return y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = s + 1; n; ++i) {
        int cnt = 0;
        for (int b = 2; b <= 10; ++b) {
            cnt += flip(i, b) == i;
            if (cnt >= 2) {
                cout << i << "\n";
                --n;
                break;
            }
        }
    }
    return 0;
}