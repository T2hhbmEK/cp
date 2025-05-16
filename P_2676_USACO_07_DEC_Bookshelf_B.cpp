#include <bits/stdc++.h>
#define maxn 20010
using namespace std;

int n, b, h[maxn], sum, ans;

int main() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) cin >> h[i];
    sort(h + 1, h + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++) {
        sum += h[i];
        if (sum >= b) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
