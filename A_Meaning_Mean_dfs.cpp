#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;

vector<pair<int, int>> tr;

void p(vector<int>& a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

int dfs(vector<int>& a) {
    int n = a.size();
    if (n == 1) return a[0];
    vector<int> aa(a);
    sort(a.begin(), a.end(), greater<int>());
    int b = a[n - 1];
    a.pop_back();
    int ans = 0;
    int ai = 0;
    for (int i = n - 2; i >= 0; --i) {
        int c = a[i];
        a[i] = (a[i] + b) / 2;
        vector<pair<int, int>> trb;
        swap(trb, tr);
        int f = dfs(a);
        a[i] = c;
        if (f > ans) {
            ans = f;
            ai = a[i];
        } else {
            swap(tr, trb);
        }
    }
    tr.push_back({b, ai});
    swap(a, aa);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    tr.clear();
    cout << dfs(a) << endl;
    for (auto [x, y] : tr) {
        cout << "(" << x << "," << y << ")";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
