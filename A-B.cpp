#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n, s[maxn], c, cnt;

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) {
        int b = s[i];
        int a = b + c;
        int l = lower_bound(s + 1, s + n + 1, a) - s;
        if (l <= n && s[l] == a) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
