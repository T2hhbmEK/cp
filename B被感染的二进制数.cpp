#include <bits/stdc++.h>
using namespace std;
void myadd(const string &a, const string &b, string &c, int d = 0, int k = 0) {
    if (k >= a.size() && k >= b.size()) {
        if (d != 0) c += '1';
        return;
    }
    if (k < a.size() && k < b.size()) {
        int x = a[k] - '0';
        int y = b[k] - '0';
        int z = x + y + d;
        d = z / 2;
        z = z % 2;
        c += '0' + z;
        myadd(a, b, c, d, k + 1);
    } else {
        int x = a[k] - '0';
        int y = 0;
        int z = x + y + d;
        d = z / 2;
        z = z % 2;
        c += '0' + z;
        myadd(a, b, c, d, k + 1);
    }
}
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string s16 = "0000" + s;
    string ans = "";
    myadd(s16, s, ans);
    // while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
