#include <bits/stdc++.h>
using namespace std;

int k, L, R, ans;

int main() {
    cin >> k >> L >> R;
    for (int i = L; i <= R; i++) {
        if (i % k == 0 || i % 10 == k) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}
