#include <iostream>
using namespace std;
int n, k, p = -1;
unsigned long long a[1000005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = n; i >= 1; --i) {
        if (a[i] % 2 == 0) {
            p = i;
            break;
        }
    }
    cout << p << endl;
    if (p > k) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
