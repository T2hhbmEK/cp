#include <iostream>
using namespace std;
int n, a[105], m, cnt;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        if (a[i] == m) {
            cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}
