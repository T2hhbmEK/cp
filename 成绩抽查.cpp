#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e3 + 5;
struct T {
    int no, s1, s2, s3, s4;
    void input() { cin >> no >> s1 >> s2 >> s3 >> s4; }
    double overall() { return (s1 + s2 + s3) * 0.7 + s4 * 0.3; }
    bool is_excellent() { return overall() >= 200; }
} a[NMAX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i].input();
    while (m--) {
        int i;
        cin >> i;
        cout << fixed << setprecision(1) << a[i].overall();
        if (a[i].is_excellent()) cout << " " << a[i].no;
        cout << endl;
    }
    return 0;
}
