#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int N = 1e3 + 7;
int n, a, cnt, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (a % 2 == 0) {
            ans += 1;
        } else {
            cnt += 1;
        }
    }
    ans += cnt / 2;
    cout << ans;
    return 0;
}