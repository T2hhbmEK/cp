#include <bits/stdc++.h>
using namespace std;

const int mod = 10000;

int main() {
    string s;
    cin >> s;
    s += '+';
    stack<long long> st;
    st.push(0);
    bool flag = false;
    for (char c : s) {
        if (isdigit(c)) {
            st.top() = st.top() * 10 + c - '0';
            continue;
        }
        if (flag) {
            long long t = st.top();
            st.pop();
            st.top() = st.top() * t % mod;
            flag = false;
        }
        if (c == '+') {
            st.push(0);
        } else if (c == '*') {
            st.push(0);
            flag = true;
        }
    }
    while (st.size() > 1) {
        long long t = st.top();
        st.pop();
        st.top() = (st.top() + t) % mod;
    }
    cout << st.top() % mod << endl;
    return 0;
}
