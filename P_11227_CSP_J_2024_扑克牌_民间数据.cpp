#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const string hs = "DCHS";
    const string ds = "A23456789TJQK";
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    int ans = 0;
    for (const auto &h : hs) {
        for (const auto &d : ds) {
            if (st.find(string() + h + d) == st.end()) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
