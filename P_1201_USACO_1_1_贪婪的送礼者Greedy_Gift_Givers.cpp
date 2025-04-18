#include <bits/stdc++.h>
using namespace std;
#define N 15
int n, m, p, iNa;
int snd[N], rcv[N];
vector<string> vName;
unordered_map<string, int> mNameIdx;
string na;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> na;
        mNameIdx[na] = i;
        vName.emplace_back(na);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> na;
        iNa = mNameIdx[na];
        cin >> p >> m;
        if (m == 0) continue;
        p /= m;
        snd[iNa] = p * m;
        for (int j = 1; j <= m; ++j) {
            cin >> na;
            rcv[mNameIdx[na]] += p;
        }
    }
    for (const auto &i : vName) {
        cout << i << " " << rcv[mNameIdx[i]] - snd[mNameIdx[i]] << "\n";
    }
    return 0;
}