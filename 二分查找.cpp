#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int n, a[maxn], q, x;

int bs(int x) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        cin >> x;
        int i = bs(x);
        if (a[i] == x)
            cout << i << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
