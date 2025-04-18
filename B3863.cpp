#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z, q;
    cin >> x >> y >> z >> q;
    int p = 2 * x + 5 * y + 3 * z;
    string ans[2] = {"No", "Yes"};
    cout << ans[p <= q] << endl << abs(p - q);
    return 0;
}
