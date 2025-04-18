#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int a = 25; a >= 0; a--) {
        int b = 100 - 4 * a, c = 600 - 3 * a;
        if (b % 7 == 0 && c % 7 == 0) {
            printf("A:%d B:%d C:%d\n", a, b / 7, c / 7);
        }
    }
    return 0;
}