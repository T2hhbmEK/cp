#include <bits/stdc++.h>
using namespace std;
#define N 205
int n, a, b, K[N], ans[N];
queue<int> qi;
void _push(int i) {
    qi.push(i);
}
void _pop(int &i) {
    i = qi.front();
    qi.pop();
}
int main() {
    cin >> n >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &K[i]);
    }
    qi.push(a);
    ans[a] = 1;
    while (!qi.empty()) {
        int i;
        _pop(i);
        int is[2];
        is[0] = i + K[i];
        is[1] = i - K[i];
        for (int j = 0; j < 2; ++j) {
            if (1 <= is[j] && is[j] <= n && ans[is[j]] == 0) {
                _push(is[j]);
                ans[is[j]] = ans[i] + 1;
                if (is[j] == b) {
                    cout << ans[i] << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}