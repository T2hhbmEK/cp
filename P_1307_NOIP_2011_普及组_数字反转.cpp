#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 0;
    cin >> n;
    while (n) {
        a = a * 10 + n % 10;
        n /= 10;
    }
    cout << a << endl;
    return 0;
}
