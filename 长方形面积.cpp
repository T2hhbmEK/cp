#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll a[4][2];
int main() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[i][j];
        }
    }
    ll w = a[1][0] - a[0][0];
    ll h = a[1][1] - a[2][1];
    cout << w * h;
    return 0;
}