#include <bits/stdc++.h>
using namespace std;
#define N 500005
void p(list<int> q) {
    for (auto a : q) {
        cout << a << " ";
    }
    cout << endl;
}
bool check(int n, int m, char *s) {
    list<int> q;
    for (size_t i = 0; i < m; ++i) {
        if (s[i] == '1') {
            q.push_back(i);
        }
    }
    if (q.size() == 0) {
        return m <= n;
    }
    if (q.size() == 1) {
        return q.front() <= n && m - q.front() - 1 <= n;
    }
    q.push_back(m);
    for (auto i = q.rbegin(), j = ++q.rbegin(); j != q.rend(); ++i, ++j) {
        *i -= *j + 1;
    }
    int d = *(++q.begin());
    if (d > n) {
        return false;
    }
    if (q.front() > d) {
        return false;
    }
    q.pop_front();
    if (q.back() > d) {
        return false;
    }
    q.pop_back();
    for (auto i = q.begin(); i != q.end(); ++i) {
        if (*i != d) {
            return false;
        }
    }
    return true;
}
int main() {
    int t, n, m;
    char s[N];
    cin >> t;
    while (t-- > 0) {
        scanf("%d%d%s", &n, &m, s);
        printf(check(n, m, s) ? "Yes\n" : "No\n");
    }
    return 0;
}