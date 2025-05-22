#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int sum = 0;
    a = (a + 4) / 4 * 4;
    for (int i = a; i < b; i += 4) {
        if (i % 400 == 0 || i % 100 != 0) {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
