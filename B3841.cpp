#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, a;
    cin >> m;
    while (m--) {
        cin >> a;
        int b = a, k = log10(a) + 1, sum = 0;
        while (b) {
            sum += pow(b % 10, k);
            b /= 10;
        }
        cout << "FT"[a == sum] << '\n';
    }
    return 0;
}
