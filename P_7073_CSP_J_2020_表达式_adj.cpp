#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long

const int maxn = 1e6 + 10;
const int maxm = maxn << 1;

struct node {
    char op;
    bool val;
    int id;
    void print() {
        cout << "node(op=" << op << ",val=" << val << ",id=" << id << ")";
    }
} x[maxn];
int cntn, n, q;
forward_list<int> adj[maxn];

void add_edge(int u, int v) {
    adj[u].push_front(v);
    // x[u].print(), cout << " -> ", x[v].print(), cout << '\n';
}

int st[maxn];
int top;

string s;

int read(int &i) {
    int ret = 0;
    if (s[i] == 'x') {
        ++i;
        while (s[i] >= '0' && s[i] <= '9') {
            ret = (ret << 3) + (ret << 1) + (s[i++] & 0xf);
        }
    } else {
        x[++cntn].op = s[i++];
        x[cntn].id = cntn;
        ret = cntn;
    }
    while (s[i] == ' ') ++i;
    return ret;
}

bitset<maxn> used;

void dfs(int u) {
    if (x[u].op == 'x') {
        used[x[u].id] = true;
    }
    for (int v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    getline(cin, s);
    cin >> n;
    cntn = n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i].val;
        x[i].op = 'x';
        x[i].id = i;
    }
    for (int i = 0; s[i];) {
        int u = read(i);
        if (x[u].op == '!') {
            int a = st[top--];
            x[u].val = !x[a].val;
            add_edge(u, a);
        } else if (x[u].op == '&') {
            int b = st[top--];
            int a = st[top--];
            x[u].val = x[a].val && x[b].val;
            if (x[u].val != (!x[a].val && x[b].val)) {
                add_edge(u, a);
            }
            if (x[u].val != (x[a].val && !x[b].val)) {
                add_edge(u, b);
            }
        } else if (x[u].op == '|') {
            int b = st[top--];
            int a = st[top--];
            x[u].val = x[a].val || x[b].val;
            if (x[u].val != (!x[a].val || x[b].val)) {
                add_edge(u, a);
            }
            if (x[u].val != (x[a].val || !x[b].val)) {
                add_edge(u, b);
            }
        }
        st[++top] = u;
    }
    assert(top == 1);
    int u = st[top];
    dfs(u);
    // for (int i = 1; i <= n; ++i) cout << used[i] << (i == n ? '\n' : ' ');
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        cout << (used[i] ? !x[u].val : x[u].val) << '\n';
    }
    return 0;
}
