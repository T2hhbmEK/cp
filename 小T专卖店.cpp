#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a = 3, b = 5, c = 1;
    int n = 100;
    int s = 100;
    for (int i = 0; i * 3 <= s; ++i) {
        for (int j = 0; i * 3 + j * 5 <= s; ++j) {
            int k = (s - i * 3 - j * 5) * 3;
            if (i + j + k == n) {
                cout << "A:" << i << " B:" << j << " C:" << k << "\n";
            }
        }
    }
    return 0;
}
