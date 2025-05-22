#include <bits/stdc++.h>
using namespace std;

#define FOR2(i, a, b) for (int i = a; i <= b; i += 2)

int k, flag;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    FOR2(a, 1, 9) FOR2(b, 0, 9) FOR2(c, 1, 9) FOR2(d, 0, 9) {
        if (a + b + c + d == k) {
            cout << a << b << c << d << '\n';
            flag = 1;
        }
    }
    if (!flag) {
        cout << -1;
    }
    return 0;
}
