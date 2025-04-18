#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    priority_queue<int> ql;
    priority_queue<int, vector<int>, greater<int>> qr;
    while (cin >> x) {
        if (x == 0) {
            ql = {}, qr = {};
            cout << endl;
        } else if (x == -1) {
            cout << ql.top() << endl;
            ql.pop();
        } else {
            if (!ql.empty() && x > ql.top()) {
                qr.push(x);
            } else {
                ql.push(x);
            }
        }
        while (qr.size() > ql.size()) ql.push(qr.top()), qr.pop();
        while (ql.size() > qr.size() + 1) qr.push(ql.top()), ql.pop();
    }
    return 0;
}
