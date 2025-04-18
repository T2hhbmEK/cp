#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
    cin >> n >> m >> k;
    int x = n / k;
    int y = m / k;
    int ans = x + y;
    if (ans == 0 && (n != 0 || m != 0)) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}