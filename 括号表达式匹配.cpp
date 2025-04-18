#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
unordered_set<char> lp = {'(', '[', '{'};  // left parentheses

bool solve() {
    char c;
    stack<char> st;
    while (cin >> c) {
        if (c == '@') break;
        if (lp.find(c) != lp.end()) {
            st.push(c);
        } else if (mp.find(c) != mp.end()) {
            if (st.empty()) {
                return 0;
            }
            if (st.top() == mp[c]) {
                st.pop();
            } else {
                return 0;
            }
        }
    }
    if (st.empty()) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
