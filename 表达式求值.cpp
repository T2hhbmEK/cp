#include <bits/stdc++.h>
using namespace std;

const int mod = 10000;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    char op;
    stack<int> st;
    cin >> a;
    st.push(a);
    while (cin >> op >> b) {
        if (op == '+')
            st.push(b % mod);
        else if (op == '-')
            st.push(mod - b % mod);
        else if (op == '*') {
            int a = st.top();
            st.pop();
            st.push(a * b % mod);
        } else if (op == '/') {
            int a = st.top();
            st.pop();
            st.push(a / b % mod);
        }
    }
    int res = 0;
    while (!st.empty()) {
        res = (res + st.top()) % mod;
        st.pop();
    }
    cout << res << endl;
    return 0;
}
