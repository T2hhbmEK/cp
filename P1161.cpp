#include <iostream>
#define maxn 2000010
using namespace std;

int main() {
    int n, b[maxn] = {};
    cin >> n;
    while (n--) {
        double a;
        int t;
        cin >> a >> t;
        for (int i = 1; i <= t; i++) {
            b[int(a * i)] ^= 1;
        }
    }
    for (int i = 1;; i++) {
        if (b[i] == 1) {
            n = i;
            break;
        }
    }
    cout << n << endl;
    return 0;
}
