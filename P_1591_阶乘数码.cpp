#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int t, n, a;

struct Bignum {
    int arr[maxn];
    int len;
    Bignum(int x) {
        memset(arr, 0, sizeof(arr));
        len = 0;
        while (x) {
            arr[++len] = x % 10;
            x /= 10;
        }
    }
    void mult(int x) {
        for (int i = 1; i <= len; i++) {
            arr[i] *= x;
        }
        flatten();
    }
    void flatten() {
        len += 5;
        for (int i = 1; i < len; i++) {
            arr[i + 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        while (arr[len] == 0) len--;
    }
    int cnt(int x) {
        int s = 0;
        for (int i = 1; i <= len; i++) {
            if (arr[i] == x) {
                s++;
            }
        }
        return s;
    }
};

void slv() {
    cin >> n >> a;
    Bignum s(1);
    for (int i = 1; i <= n; i++) {
        s.mult(i);
    }
    cout << s.cnt(a) << endl;
}

int main() {
    cin >> t;
    while (t--) {
        slv();
    }
    return 0;
}
