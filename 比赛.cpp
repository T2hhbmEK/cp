#include <iostream>
using namespace std;

int n, m, t;

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < t; ++i) {
        cout << i % n + 1 << ' ' << i % m + 1 << '\n';
    }
    return 0;
}
