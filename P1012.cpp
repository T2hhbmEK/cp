#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& x, const string& y) {
    string s = x + y;
    string t = y + x;
    return s > t;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    return 0;
}
