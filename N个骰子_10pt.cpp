#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e6 + 5;

int n, a, b;

void solve() {
    cin >> n >> a >> b;
    // red 1 4 black 2 3 5 6
    // 6k+2, 6k+3, 6k+5, 6k+6
    // 6k+1: 6(k-1)+2+5
    // 6k+4: 6(k-1)+5+5
    // 2 3 5 6 can represent all numbers from 2*k to 6*k
    // except when k = 1, cannot reperesent 4
    // enumerate number of 4s
    for (int i = 0; i * 4 <= a; ++i) {
        int j = (a - 4 * i);
        int k = (n - i - j);
        if (k == 1 && b == 4) continue;
        if (b >= 2 * k && b <= 6 * k) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    while (m--) {
        solve();
    }
    return 0;
}
