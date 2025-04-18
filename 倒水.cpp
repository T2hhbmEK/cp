#include <iostream>
using namespace std;
int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int x1 = 0, x2 = 0;
    while (k--) {
        if (x1 == a) {
            x1 = 0;
        } else if (x2 == 0) {
            x2 = b;
        } else {
            if (x1 + x2 > a) {
                x2 = x1 + x2 - a;
                x1 = a;
            } else {
                x1 = x1 + x2;
                x2 = 0;
            }
        }
    }
    cout << x1 << " " << x2;
    return 0;
}