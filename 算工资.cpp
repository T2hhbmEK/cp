#include <iostream>
using namespace std;

int m, sum, d;

int main() {
    cin >> m;
    for (int i = 1;; ++i) {
        for (int j = 1; j <= i; ++j) {
            sum += i;
            if (++d == m) {
                cout << sum;
                return 0;
            }
        }
    }
    return 0;
}
