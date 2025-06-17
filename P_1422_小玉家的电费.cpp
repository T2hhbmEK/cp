#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double s = 0.4463 * min(150, n) + 0.4663 * max(0, min(400, n) - 150) +
               0.5663 * max(0, n - 400);
    cout << fixed << setprecision(1) << s << endl;
    return 0;
}
