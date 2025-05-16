#include <bits/stdc++.h>
#define maxn 500
using namespace std;

struct Bignum {
    int arr[maxn], len;
    Bignum(int x) {
        memset(arr, 0, sizeof(arr));
        len = 0;
        while (x) {
            arr[len++] = x % 10;
            x /= 10;
        }
    }
    Bignum(Bignum& x) {
        len = x.len;
        memcpy(arr, x.arr, sizeof(arr));
    }
    friend ostream& operator<<(ostream& os, Bignum& x) {
        for (int i = x.len - 1; i >= 0; i--) {
            os << x.arr[i];
        }
        return os;
    }
    void prt2() {
        for (int i = maxn - 1; i >= 0; i--) {
            cout << arr[i];
            if (i % 50 == 0) cout << endl;
        }
    }
    void faltten() {
        for (int i = 0; i < len; i++) {
            if (i + 1 < maxn) arr[i + 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        while (len > 0 && arr[len - 1] == 0) len--;
    }
    Bignum& operator*=(Bignum& x) {
        Bignum z(0);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < x.len && i + j < maxn; j++) {
                z.arr[i + j] += arr[i] * x.arr[j];
            }
        }
        z.len = min(maxn, len + x.len);
        z.faltten();
        *this = z;
        return *this;
    }
    Bignum& operator-=(int x) {
        arr[0] -= x;
        for (int i = 0; i < len; i++) {
            if (arr[i] < 0) {
                int y = (-arr[i] + 10 - 1) / 10;
                if (i + 1 < maxn) arr[i + 1] -= y;
                arr[i] += y * 10;
                // assert(arr[i] >= 0 && arr[i] <= 9);
            }
        }
        while (len > 0 && arr[len - 1] == 0) len--;
        return *this;
    }
};

int p;
int main() {
    cin >> p;
    Bignum ans(1), a(2);
    for (int i = 0; (1 << i) <= p; i++) {
        if ((1 << i) & p) {
            ans *= a;
        }
        a *= a;
    }
    int len = p * log10(2.0) + 1;
    cout << len << endl;
    ans -= 1;
    ans.prt2();
    return 0;
}
