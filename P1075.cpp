#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int p;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p = n / i;
            break;
        }
    }
    cout << p << endl;
    return 0;
}