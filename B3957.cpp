#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N], n, ans;
bool check(int x) {
    int y = sqrt(x);
    return y * y == x;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (check(a[i] + a[j])) ans++;
        }
    }
    cout << ans;
    return 0;
}
