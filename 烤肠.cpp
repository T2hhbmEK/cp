#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int w = 1;
    int d = 1;
    int q = a;
    while (q < n) {
        d += 1;
        if (d > 7) {
            d = 1;
            w += 1;
        }
        q += a;
        if (d == 6 || d == 7) q += b;
    }
    cout << w << " ";
    cout << d << endl;
    return 0;
}