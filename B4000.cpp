#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    s = h * 3600 + m * 60 + s + k;
    h = s / 3600 % 24;
    m = s / 60 % 60;
    s = s % 60;
    cout << h << ' ' << m << ' ' << s;
    return 0;
}
