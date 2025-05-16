#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m, a;
int cnt[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i <= n; i++) {
        while (cnt[i]--) {
            cout << i << " ";
        }
    }
    return 0;
}
