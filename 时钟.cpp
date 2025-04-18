#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int N = 1e5 + 7;
int t, a, b, c, d;
int nxt(int a) {
    a += 1;
    if (a > 12) a -= 12;
    return a;
}
int pre(int a) {
    a -= 1;
    if (a < 1) a += 12;
    return a;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        int fc = 0, fd = 0;
        for (int i = a; i != b; i = nxt(i)) {
            if (i == c) fc = 1;
            if (i == d) fd = 1;
        }
        if (fc == fd) {
            cout << 3 << "\n";
        } else {
            cout << 4 << "\n";
        }
    }
    return 0;
}