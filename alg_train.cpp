#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        s += x;
    }
    cout << fixed << setprecision(2);
    cout << (double)s / n << endl;
    return 0;
}