#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int N = 1e5 + 7;

queue<int> q;
int n;

int main() {
    cin >> n;
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            q.push(x);
        } else if (op == 2) {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << '\n';
            }
        } else if (op == 3) {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << '\n';
            }
        } else {
            if (!q.empty()) {
                q.pop();
            }
        }
    }
    return 0;
}