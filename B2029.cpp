#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    const double pi = 3.14;
    int h, r;
    cin >> h >> r;
    int n = ceil(20000 / (pi * r * r * h));
    cout << n;
    return 0;
}
