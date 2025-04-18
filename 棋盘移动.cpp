#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int N = 1e5 + 7;
int a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    int ans = min(c, d) - max(a, b) + 1;
    ans = max(ans, 0);
    cout << ans;
    return 0;
}