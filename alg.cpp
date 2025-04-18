#include <iostream>
using namespace std;
int n, a, zd[10], he;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> a;
            if (a > zd[j]) {
                zd[j] = a;
            }
        }
    }
    for (int i = 1; i <= 4; ++i) {
        he += zd[i];
    }
    cout << he;
    return 0;
}