#include <bits/stdc++.h>
#define maxn 110
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

int n, a[maxn];

int main() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        int cnt = 0;
        rep(j, 1, i - 1) if (a[j] < a[i]) cnt++;
        cout << cnt << " \n"[i == n];
    }
    return 0;
}
