#include <bits/stdc++.h>
using namespace std;
int main() {
    double s = 0;
    int n = 1e8;
    for (int i = 1; i <= n; i++) {
        s += 1.0 / i;
    }
    cout << s << endl;
    return 0;
}
