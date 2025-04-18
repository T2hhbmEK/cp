#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // bool f = 0;
    // for (int i = 1; i * i * i <= n; i++) {
    // if (i * i * i == n) {
    // f = 1;
    // }
    // }
    // if (f) cout << "Yes"; else cout << "No";
    int a = cbrt(n); // cube root
    // int a = sqrt(n); // square root
    if (a * a * a == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
