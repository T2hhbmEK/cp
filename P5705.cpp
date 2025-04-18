#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double a;
    cin >> a;
    int b = a * 10;
    cout << b % 10;
    cout << '.';
    cout << b / 10 % 10;
    cout << b / 100 % 10;
    cout << b / 1000 % 10;
    return 0;
}
