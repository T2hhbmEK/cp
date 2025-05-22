#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    int c = 0;
    // square_root
    for (int i = 0; i * i <= a; i++) {
        if (a % i == 0) {
            c++;
        }
    }
    cout << c;
    return 0;
}
