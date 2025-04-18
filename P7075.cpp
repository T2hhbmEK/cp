#include <bits/stdc++.h>
using namespace std;
#define N 100'005
typedef long long ll;
int q;
ll rr[N];
void p(int y, int m, int d) {
    if (y > 0) {
        printf("%d %d %d\n", d, m, y);
    } else {  // y=0 => 1 BC
        printf("%d %d %d BC\n", d, m, 1 - y);
    }
}
int ydays(int y) {
    if (y < 1582) {
        return 365 + (y % 4 == 0);
    }
    if (y == 1582) {
        return 355;
    }
    return 365 + (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
}
ll r_YYYY_12_31(int yyyy) {
    ll r = -1;
    for (int i = -4712; i <= yyyy; ++i) {
        r += ydays(i);
    }
    return r;
}
ll r_YYYY_12_31_fast(int y) {
    ll r = -1;
    if (y == -4713) {
        return r;
    }
    r += 366;
    if (y == -4712) {  // first leap year, 4713 BC
        return r;
    }
    // y > -4712
    ll z = y + 4712;
    r += z * 365 + z / 4;
    if (y <= 1581) {
        return r;
    }
    r -= 10;
    // y > 1582
    if (y <= 1600) {
        return r;
    }
    z = y - 1600;
    r -= z / 400 * 3;
    r -= z % 400 / 100;
    return r;
}
int dz366[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
int dz365[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int dz355[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 294, 324, 355};
int accmulated_dz(int i, int dz) {
    switch (dz) {
        case 366:
            return dz366[i];
            break;
        case 355:
            return dz355[i];
            break;
        default:
            return dz365[i];
            break;
    }
}
int y_r(ll r) {
    int i = -4713;
    int j = 1'000'000'000;
    while (j - i > 1) {       // (i, j]
        int k = (i + j) / 2;  // r(k) = r_YYYY_12_31(k-1) + 1 ~ r_YYYY_12_31(k)
        if (r <= r_YYYY_12_31_fast(k)) {
            j = k;
        } else {
            i = k;
        }
        // printf("%lld r(%d)=%lld r(%d)=%lld\n", r, i, r_YYYY_12_31_fast(i), j,
        //        r_YYYY_12_31_fast(j));
    }
    return j;
}
void ymd_r(int y, int &m, int &d, ll r) {
    d = r - r_YYYY_12_31_fast(y - 1);
    int dz = ydays(y);
    for (m = 1; m <= 12; ++m) {
        if (accmulated_dz(m, dz) >= d) {
            d = d - accmulated_dz(m - 1, dz);
            if (y == 1582 && m == 10 && d > 4) {
                d += 10;
            }
            return;
        }
    }
}
int main() {
    // // check r_YYYY_12_31_fast and ydays
    // // -1 1721057
    // // 0 1721423
    // // 1 1721788
    // int yy[10] = {-4713, -1, 0, 1, 1581, 1582, 1600, 1700, 2000, 9999999};
    // for (int i = 0; i < 10; ++i) {
    //     cout << yy[i] << " " << r_YYYY_12_31_fast(yy[i]) << " "
    //          << r_YYYY_12_31(yy[i]) << " " << ydays(yy[i]) << endl;
    // }
    // return 0;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        scanf("%lld", &rr[i]);
    }
    for (int i = 1; i <= q; ++i) {
        int y = y_r(rr[i]), m, d;
        ymd_r(y, m, d, rr[i]);
        p(y, m, d);
    }
    return 0;
}