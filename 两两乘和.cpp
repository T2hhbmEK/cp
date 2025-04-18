#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, t[N], pre[N], s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        pre[i] = pre[i - 1] + t[i];
    }
    for (int i = 1; i <= n; ++i) {
        s += t[i] * (pre[n] - pre[i]);
    }
    cout << s;
    return 0;
}