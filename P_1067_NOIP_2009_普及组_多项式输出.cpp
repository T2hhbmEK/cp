#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, a, cnt;

int main() {
    cin >> n;
    for (int i = n; i >= 0; i--) {
        cin >> a;
        if (a == 0) continue;
        if (cnt > 0 && a > 0) cout << '+';
        if (a < 0) cout << '-';
        a = abs(a);
        if (a != 1 || i == 0) cout << a;
        if (i > 0) {
            cout << 'x';
            if (i > 1) {
                cout << '^' << i;
            }
        }
        cnt++;
    }
    if (cnt == 0) cout << 0;
    cout << endl;
    return 0;
}
