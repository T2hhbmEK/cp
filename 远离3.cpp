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
const int MAXK = 1000;
vector<int> a;

void init() {
    for (int i = 1; a.size() < MAXK; i++) {
        if (i % 3 != 0 && i % 10 != 3) a.push_back(i);
    }
}

void solve() {
    int k;
    cin >> k;
    cout << a[k - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n = 1;
    cin >> n;
    init();
    while (n--) {
        solve();
    }
    return 0;
}
