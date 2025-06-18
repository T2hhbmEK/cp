#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx = 0, cnt = 0;
    cin >> n;
    for (int i = 1, a, p = -1; i <= n; i++) {
        cin >> a;
        if (a - p != 1) cnt = 0;
        cnt++;
        mx = max(mx, cnt);
        p = a;
    }
    cout << mx << endl;
    return 0;
}
