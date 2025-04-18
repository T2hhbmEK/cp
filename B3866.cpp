#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c = 0;
    cin >> n;
    while (n != 495) {
        int a1 = n % 10;
        int a2 = n / 10 % 10;
        int a3 = n / 100 % 10;
        int amax = max(a1, max(a2, a3));
        int amin = min(a1, min(a2, a3));
        n = (amax - amin) * 99;
        c++;
    }
    cout << c;
    return 0;
}
