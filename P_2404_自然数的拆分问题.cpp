#include <bits/stdc++.h>
#define endl '\n'
#define maxn 10
using namespace std;

int n, a[maxn];

void dfs(int k, int n) {
    if (n == 0) {
        if (k <= 2) return;
        for (int i = 1; i < k; i++) {
            if (i != 1) cout << "+";
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = a[k - 1]; i <= n; i++) {
        a[k] = i;
        dfs(k + 1, n - i);
    }
}

int main() {
    a[0] = 1;
    cin >> n;
    dfs(1, n);
    return 0;
}
