#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), id(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = i;
    }
    function<bool(int, int)> cmp = [&](int i, int j) {
        if (a[i] == a[j]) return i < j;
        return a[i] < a[j];
    };
    sort(id.begin() + 1, id.end(), cmp);
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            int v;
            cin >> v;
            if (v == a[x]) continue;
            a[x] = v;
            for (int j = 1; j < n; j++) {
                if (cmp(id[j + 1], id[j])) {
                    swap(id[j], id[j + 1]);
                }
            }
            for (int j = n; j > 1; j--) {
                if (cmp(id[j], id[j - 1])) {
                    swap(id[j], id[j - 1]);
                }
            }
        } else {
            int l = lower_bound(id.begin() + 1, id.end(), x, cmp) - id.begin();
            cout << l << '\n';
        }
    }
    return 0;
}
