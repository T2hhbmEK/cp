#include <iostream>
// #define int long long
#define maxn 32
using namespace std;
int n, a[maxn] = {0, 1};
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a[j] += a[j - 1];
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
