#include <bits/stdc++.h>
using namespace std;
// int a[1005][105];
int a[105];
int tj;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int zf = 0;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
            zf += a[i];
        }
        double pjf = 1.0 * zf / m;
        for (int i = 1; i <= m; ++i) {
            if (a[i] < pjf) {
                tj += 1;
            }
        }
    }
    cout << tj;
    return 0;
}
