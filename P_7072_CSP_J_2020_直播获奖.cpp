#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, w;
    cin >> n >> w;
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        int k = max(1, i * w / 100);
        if (q1.empty() || a > q1.top()) {
            q1.push(a);
        } else {
            q2.push(a);
        }
        while (q1.size() < k) {
            q1.push(q2.top());
            q2.pop();
        }
        while (q1.size() > k) {
            q2.push(q1.top());
            q1.pop();
        }
        cout << q1.top() << ' ';
    }
    return 0;
}
