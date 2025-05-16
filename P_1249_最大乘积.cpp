#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

struct Bignum {
    int arr[maxn], len;
    Bignum(int x) {
        memset(arr, 0, sizeof(arr));
        len = 0;
        while (x) {
            arr[++len] = x % 10;
            x /= 10;
        }
    }
};

Bignum& operator*=(Bignum& x, int y) {
    for (int i = 1; i <= x.len; i++) {
        x.arr[i] *= y;
    }
    x.len += 10;
    for (int i = 1; i < x.len; i++) {
        x.arr[i + 1] += x.arr[i] / 10;
        x.arr[i] %= 10;
    }
    while (x.arr[x.len] == 0) x.len--;
    return x;
}

ostream& operator<<(ostream& os, Bignum& x) {
    for (int i = x.len; i >= 1; i--) {
        os << x.arr[i];
    }
    return os;
}

int n;
int a[maxn], m;

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        a[m++] = i;
        n -= i;
    }
    for (int i = m - 1; n--; i = (i + m - 1) % m) {
        a[i]++;
    }
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    Bignum s(1);
    for (int i = 0; i < m; i++) {
        s *= a[i];
    }
    cout << s << endl;
    return 0;
}
