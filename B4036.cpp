#include <bits/stdc++.h>
using namespace std;

int f(int a) {
    int sum = 0;
    while (a) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (f(a) % 7 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
