#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    int pre = min(x - 1, 5);
    n += x - 1;
    int tot = n / 7 * 5 + min(n % 7, 5);
    tot -= pre;
    cout << 250 * tot << endl;
    return 0;
}
