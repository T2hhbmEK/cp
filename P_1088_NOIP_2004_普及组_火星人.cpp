#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

int n, m, a[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) next_permutation(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    return 0;
}
