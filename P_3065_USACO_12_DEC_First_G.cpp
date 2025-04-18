#include <bits/stdc++.h>
using namespace std;
#define N 30'010
#define NN 300'010
int n, nxt[NN][26], cnt;
bool has[NN];
string s;
vector<string> a;
vector<string> ans;
unordered_set<int> idx_set;
vector<int> idx;
int main() {
    cin >> n;
    while (n > 0) {
        cin >> s;
        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            int j = s[i] - 'a';
            if (!nxt[p][j]) {
                nxt[p][j] = ++cnt;
            }
            p = nxt[p][j];
        }
        has[p] = 1;
        a.emplace_back(s);
        --n;
    }
    for (const auto& s : a) {
        idx_set.clear();
        idx.clear();
        int p = 0;
        // cout << s;
        for (int i = 0; i < s.size(); ++i) {
            int j = s[i] - 'a';
            p = nxt[p][j];
            if (idx_set.find(j) == idx_set.end()) {
                idx_set.insert(j);
                idx.push_back(j);
                // cout << " " << j;
            }
        }
        // cout << endl;
        assert(has[p]);
        int q = 0;
        while (!has[q]) {
            for (const int i : idx) {
                if (nxt[q][i]) {
                    q = nxt[q][i];
                    // cout << char('a' + i);
                    break;
                }
            }
        };
        // cout << endl;
        if (q == p) {
            ans.emplace_back(s);
        }
    }
    cout << ans.size() << endl;
    for (const auto& s : ans) {
        cout << s << endl;
    }
    return 0;
}