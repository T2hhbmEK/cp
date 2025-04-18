#include <bits/stdc++.h>
using namespace std;

int n, a;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        int cnt = 0;
        for (int j = 2; j * j <= a; j++) {
            if (a % j == 0) cnt++;
            while (a % j == 0) a /= j;
        }
        if (a > 1) cnt++;
        cout << (cnt == 2) << '\n';
    }
    return 0;
}
