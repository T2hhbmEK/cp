#include <iostream>
using namespace std;

int n, m, t;

int main() {
    cin >> n >> m >> t;
    int i = 1, j = 1;
    while (t--) {
        cout << i << ' ' << j << '\n';
        if (++i > n) i = 1;
        if (++j > m) j = 1;
    }
    return 0;
}
