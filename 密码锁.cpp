#include <bits/stdc++.h>
using namespace std;

int n, range;
int a[10];

void dfs(int k) {
    if (k > n) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i <= range; ++i) {
        a[k] = i;
        dfs(k + 1);
        // a[k] = 0; // 下次循环就覆盖了，可以省略回溯
    }
}

int main() {
    cin >> n >> range;
    dfs(1);
    return 0;
}
