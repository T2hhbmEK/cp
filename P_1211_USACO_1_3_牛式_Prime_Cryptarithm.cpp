#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool a[10];
bool check(int x, int n) {
    while (n--) {
        if (!a[x % 10]) return false;
        x /= 10;
    }
    return x == 0;
}
void p(int i, int j) {
    cout << "  " << i << "\n";
    cout << "x  " << j << "\n";
    cout << "-----\n";
    cout << "  " << i * (j % 10) << "\n";
    cout << " " << i * (j / 10) << "\n";
    cout << "-----\n";
    cout << " " << i * j << "\n\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 111; i <= 999; ++i) {
        if (!check(i, 3)) continue;
        for (int j = 11; j <= 99; ++j) {
            if (check(j, 2) &&
                check(i * (j % 10), 3) &&
                check(i * (j / 10), 3) &&
                check(i * j, 4)) ++ans;
        }
    }
    cout << ans;
    return 0;
}