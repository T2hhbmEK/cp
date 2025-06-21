#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, s, mx = 0, mxi = 0;
    for (int i = 1; i <= 7; i++)
        if (cin >> a >> b, s = a + b, s > 8 && s > mx) mx = s, mxi = i;
    cout << mxi << endl;
    return 0;
}
