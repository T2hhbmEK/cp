#include <bits/stdc++.h>
using namespace std;

int n;
int sx, sy, ex, ey;

int main() {
    cin >> n >> sx >> sy >> ex >> ey;
    cout << abs(ex - sx) + abs(ey - sy);
    return 0;
}
