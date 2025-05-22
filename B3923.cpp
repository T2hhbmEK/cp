#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    int sum = a + b;
    for (int i = 3; i <= n; i++) {
        swap(a, b);
        b += a;
        sum += b;
        if (b >= m) break;
    }
    cout << sum;
    return 0;
}
