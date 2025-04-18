#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 2e5 + 7;
int n, x;
int a[N];
list<list<int>> s;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1 || a[i] != a[i - 1]) {
            s.push_back({i});
        } else {
            s.back().push_back(i);
        }
    }
    while (!s.empty()) {
        for (auto &a : s) {
            cout << a.front() << " ";
            a.erase(a.begin());
        }
        cout << endl;
        for (auto it = s.begin(); it != s.end();) {
            if (it->empty()) {
                it = s.erase(it);
            } else {
                ++it;
            }
        }
        for (auto it = s.begin(); it != s.end();) {
            auto nx = next(it);
            while (nx != s.end() && a[nx->front()] == a[it->front()]) {
                it->splice(it->end(), *nx);
                nx = s.erase(nx);
            }
            it = nx;
        }
    }
    return 0;
}
