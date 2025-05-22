#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n + 1);
    vector<int> rank(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) rank[a[i].second] = i;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            int v;
            cin >> v;
            a[rank[x]].first = v;
            for (int i = rank[x]; i < n && a[i] > a[i + 1]; i++) {
                swap(rank[a[i].second], rank[a[i + 1].second]);
                swap(a[i], a[i + 1]);
            }
            for (int i = rank[x]; i > 1 && a[i] < a[i - 1]; i--) {
                swap(rank[a[i].second], rank[a[i - 1].second]);
                swap(a[i], a[i - 1]);
            }
        } else {
            cout << rank[x] << '\n';
        }
    }
    return 0;
}
