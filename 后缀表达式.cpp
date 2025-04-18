#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    stack<int> st;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '@') break;
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (s[i] == '+') st.push(a + b);
            if (s[i] == '-') st.push(a - b);
            if (s[i] == '*') st.push(a * b);
            if (s[i] == '/') st.push(a / b);
        } else {
            int x = 0;
            while (isdigit(s[i])) {
                x = x * 10 + s[i] - '0';
                i++;
            }
            st.push(x);
        }
    }
    cout << st.top() << endl;
    return 0;
}
