#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (400 % a == 0) {
        cout << 400 / a;
    } else {
        cout << -1;
    }
    return 0;
}
