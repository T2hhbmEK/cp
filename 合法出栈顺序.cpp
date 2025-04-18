#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int N = 1e5 + 7;

string s;

int main() {
    while (cin >> s) {
        stack<char> st;
        int i = 0;
        for (char ch = 'a'; ch <= 'z'; ch += 1) {
            st.push(ch);
            while (!st.empty() && st.top() == s[i]) {
                st.pop();
                i += 1;
            }
        }
        if (st.empty() && i == s.size()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}