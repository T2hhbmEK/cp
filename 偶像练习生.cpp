#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    int amax = 0, bmax = 0, cmax = 0, dmax = 0;
    while (n--) {
        cin >> a >> b >> c >> d;
        amax = max(amax, a);
        bmax = max(bmax, b);
        cmax = max(cmax, c);
        dmax = max(dmax, d);
    }
    cout << amax + bmax + cmax + dmax << endl;
    return 0;
}
