#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (const auto &ch : s) {
        ans += ch == '1';
    }
    cout << ans << endl;
    return 0;
}
