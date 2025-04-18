#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 5;
int n, s, c, x, ans;
vector<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s >> c;
    if (n >= c) {
        cout << c;
        return 0;
    }
    for (int i = 0; i < c; ++i) {
        cin >> x;
        q.push_back(x);
    }
    sort(q.begin(), q.end());
    ans = q.back() - q.front() + 1;
    for (int i = 0; i < c - 1; ++i) {
        q[i] = q[i + 1] - q[i] - 1;
    }
    q.pop_back();
    partial_sort(q.begin(), q.begin() + n - 1, q.end(), greater<int>{});
    for (int i = 0; i < n - 1 && i < q.size(); ++i) {
        ans -= q[i];
    }
    cout << ans;
    return 0;
}