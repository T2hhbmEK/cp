#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a[11], cnt;

void dfs(int k, int rem, bool show = false) {
    if (k > 10) {
        if (rem != 0) return;
        if (show) {
            for (int i = 1; i < k; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        ++cnt;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        a[k] = i;
        dfs(k + 1, rem - i, show);
    }
}

int main() {
    cin >> n;
    dfs(1, n);
    cout << cnt << endl;
    dfs(1, n, true);
    return 0;
}
