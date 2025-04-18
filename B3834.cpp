#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    int ans = 0;
    // square_root
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
