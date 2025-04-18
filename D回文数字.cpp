#include <bits/stdc++.h>
using namespace std;

bool cmpLT(string &a, string &b) {  // a < b
    int i = 0;
    int n = a.size();
    while (a[i] == b[i] && i < n) i++;
    if (i >= n) return false;
    return a[i] < b[i];
}

bool check9(string &a) {
    int hf = a.size() / 2;
    for (int i = 0; i <= hf; i++) {
        if (a[i] != '9') return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string ans = s;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        ans[j] = ans[i];
    }
    if (!cmpLT(s, ans)) {
        if (check9(ans)) {
            ans = '1' + ans;
            ans.back() = '1';
            for (int i = 1; i < ans.size() - 1; i++) ans[i] = '0';
        } else {
            int i = (ans.size() - 1) / 2, j = n - 1 - i;
            while (ans[i] == '9') {
                ans[i] = ans[j] = '0';
                i--, j++;
            }
            ans[i] = ans[j] = ans[i] + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
