#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> cnt(601, 0);
    int l = 600, r = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
        l = min(l, a);
        r = max(r, a);
        int k = max(1, i * w / 100);
        int sum = 0;
        int j = r;
        for (; sum < k; --j) sum += cnt[j];
        cout << ++j << ' ';
    }
    return 0;
}
