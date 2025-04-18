#include <bits/stdc++.h>
using namespace std;
string s, t;
size_t x;
int main() {
    cin >> s >> t;
    x = s.find(t, x);
    while (x != string::npos) {
        cout << x << " ";
        x = s.find(t, x + 1);
    }
    return 0;
}