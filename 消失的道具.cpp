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
    long long L = 1, R = n;
    while (L < R) {
        long long mid = (L + R) >> 1;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << L;
    return 0;
}
