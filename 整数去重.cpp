#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 5;
int n, a, cnt[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        cnt[a]++;
        if (cnt[a] == 1) cout << a << ' ';
    }
    return 0;
}
