#include <bits/stdc++.h>
using namespace std;

int a[1005];
int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int i;
        cin >> i;
        a[i] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << i << " ";
            cnt++;
        }
    }
    if (cnt == 0) cout << n;
    return 0;
}
