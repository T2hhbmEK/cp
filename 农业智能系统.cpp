#include<bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z, ans;
    cin >> x >> y >> z;
    if (y <= x) {
        ans = (z + x - 1) / x;
    } else {
        ans = z / (y + x + x) * 3;
        z = z % (y + x + x);
        if (z > y + x) {
            ans += 3;
        } else if (z > y) {
            ans += 2;
        } else if (z > 0) {
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}