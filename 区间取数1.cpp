#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve1() {
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] > k;
        a[i] += a[i - 1];
    }
    int ans = 0;
    for (int i = c; i <= n; i++) {
        if (a[i] - a[i - c] == 0) ans++;
    }
    cout << ans;
}

void solve2() {
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    list<int> q;

    for (int i = 1, j = 1; j <= n; j++) {
        while (!q.empty() && a[q.back()] <= a[j]) q.pop_back();
        q.push_back(j);
        while (!q.empty() && q.front() < i) q.pop_front();
        if (j < i + c - 1) continue;
        if (a[q.front()] <= k) ans++;
        i++;
    }
    cout << ans;
}

signed main() {
    solve1();
    return 0;
}
