#include <bits/stdc++.h>
using namespace std;

long long n;

bool check(long long k) {
    long long x = n;
    long long cnt = 0;
    while (x > 0) {
        if (x >= k) {
            cnt += k;
            x -= k;
            x -= x / 10;
        } else {
            cnt += x;
            x = 0;
        }
    }
    return cnt * 2 >= n;
}

int main() {
    cin >> n;
    long long ans = 1;
    while (!check(ans)) ans++;
    cout << ans;
    return 0;
}
