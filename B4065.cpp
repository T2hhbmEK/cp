#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        int sum = 0;
        while (a) {
            sum += a % 10;
            a /= 10;
        }
        if (sum > ans) ans = sum;
    }
    cout << ans;
    return 0;
}
