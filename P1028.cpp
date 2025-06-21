#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, f[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= (i >> 1); j++) {
            f[i] += f[j];
        }
    }
    cout << f[n] << endl;
    return 0;
}