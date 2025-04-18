#include <bits/stdc++.h>
using namespace std;
#define N 100010
string a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    int x = 1, y = 1;
    for (const auto& c : a) {
        x *= c - 'A' + 1;
    }
    for (const auto& c : b) {
        y *= c - 'A' + 1;
    }
    if (x % 47 == y % 47) {
        cout << "GO";
    } else {
        cout << "STAY";
    }
    return 0;
}