#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 != 0) cnt++;
    }
    cout << cnt << " " << n - cnt;
    return 0;
}
