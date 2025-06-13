#include <bits/stdc++.h>
#define mod 10000
#define maxn 1000005
using namespace std;

int n;
int f[maxn][3];
// f[i][0] flat end
// f[i][1] missing upper block
// f[i][2] missing lower block

int main() {
    cin >> n;
    f[0][0] = f[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        // 01 011 001 011
        // 01 022 011 001
        f[i][0] += f[i - 1][0] + f[i - 2][0];
        f[i][0] += f[i - 1][1] + f[i - 1][2];
        f[i][0] %= mod;
        // 011 011
        // 00  01
        f[i][1] += f[i - 1][2] + f[i - 2][0];
        f[i][1] %= mod;
        // 00  01
        // 011 011
        f[i][2] += f[i - 1][1] + f[i - 2][0];
        f[i][2] %= mod;
    }
    cout << f[n][0] << endl;
    return 0;
}
