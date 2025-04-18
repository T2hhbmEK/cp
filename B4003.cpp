#include <bits/stdc++.h>
using namespace std;

string ans[26] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
};

void init() {
    for (int i = 1; i < 26; i++) {
        ans[i] = ans[i - 1].substr(1) + ans[i - 1][0];
        // cout << ans[i] << endl;
    }
}
int main() {
    init();
    int n;
    cin >> n;
    cout << ans[n % 26];
    return 0;
}
