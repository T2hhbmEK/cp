/*
贪心排序，非正解，45分
用无法通过的样例举例说明
2 2 100
51 50
103 100
*/

#include <bits/stdc++.h>
using namespace std;

int t, n, m, s;
vector<int> w, v, idx;

bool cmp(int i, int j) { return v[i] * w[j] > v[j] * w[i]; }

int main() {
    cin >> t >> n >> m;
    w.resize(n + 1);
    v.resize(n + 1);
    idx.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    t--;
    while (t--) {
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin() + 1, idx.end(), cmp);
        s = 0;
        for (int i = 1; i <= n; ++i) {
            if (v[idx[i]] <= w[idx[i]]) break;
            s += m / w[idx[i]] * v[idx[i]];
            m %= w[idx[i]];
        }
        m += s;
        swap(v, w);
    }
    cout << m << endl;
    return 0;
}
