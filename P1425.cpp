#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int f = (c * 60 + d) - (a * 60 + b);
    int e = f / 60;
    f %= 60;
    printf("%d %d", e, f);
    return 0;
}
