#include <bits/stdc++.h>
using namespace std;
#define N 30'010
#define NN 300'010
int n, nxt[NN][26], cnt;
bool has[NN];
string s;
vector<string> a;
vector<string> ans;
struct edge {
    int nxt;
    int to;
    int fr;
} edges[1000];
int head[26], edge_cnt = -1;
bool visiting[26], visited[26];
void add(int i, int j) {
    edges[++edge_cnt].nxt = head[i];
    edges[edge_cnt].to = j;
    edges[edge_cnt].fr = i;
    head[i] = edge_cnt;
}
bool dfs(int i) {
    bool ret = false;
    for (int k = head[i]; ~k; k = edges[k].nxt) {
        int j = edges[k].to;
        if (visiting[j]) {
            return true;
        }
        visiting[j] = true;
        ret = ret || dfs(j);
        visiting[j] = false;
        visited[j] = true;
    }
    return ret;
}
bool has_loop() {
    bool ret = false;
    memset(visited, 0, sizeof(visited));
    memset(visiting, 0, sizeof(visited));
    for (int i = 0; i < 26; ++i) {
        if (!(visiting[i] || visited[i])) {
            visiting[i] = true;
            ret = ret || dfs(i);
            visiting[i] = false;
            visited[i] = true;
        }
    }
    return ret;
}
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
        memset(head, -1, sizeof(head)), edge_cnt = -1;
        int p = 0;
        bool ok = true;
        for (int i = 0; i < s.size(); ++i) {
            int j = s[i] - 'a';
            if (has[p]) {
                ok = false;
                break;
            }
            for (int k = 0; k < 26; ++k) {
                if (k != j && nxt[p][k]) {
                    add(j, k);  // j < k
                }
            }
            p = nxt[p][j];
        }
        if (ok) {
            for (int i = 0; i <= edge_cnt; ++i) {
                auto& e = edges[i];
            }
            ok = !has_loop();
        }
        if (ok) ans.emplace_back(s);
    }
    cout << ans.size() << endl;
    for (const auto& s : ans) {
        cout << s << endl;
    }
    return 0;
}