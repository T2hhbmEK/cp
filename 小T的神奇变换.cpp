#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

void solve() {
    int n, q;
    cin >> n >> q;
    string s, w;
    cin >> s >> w;
    bool cnt[3] = {};
    for (char c : w) {
        cnt[c - '0'] = !cnt[c - '0'];
    }
    if (cnt[1]) reverse(s.begin(), s.end());
    if (cnt[2]) REP(i, s.size()) s[i] = '0' + !(s[i] - '0');
    cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
