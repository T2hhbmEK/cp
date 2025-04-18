#include <bits/stdc++.h>
using namespace std;

bool f[1000005];

void init() {
    for (int x = 1; x < 1000; x++) {
        for (int y = x; x * x + y * y <= 1000000; y++) {
            int a = x * x + y * y;
            f[a] = true;
        }
    }
}

int main() {
    init();
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (f[a]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
