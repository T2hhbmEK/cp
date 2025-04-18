#include <bits/stdc++.h>
using namespace std;

struct node {
    char op;
    bool v;
    shared_ptr<node> l, r;
    int id;
    void print() {
        cout << "node(op=" << op << ",v=" << v << ",id=" << id << ")";
    }
};

void dfs(shared_ptr<node> root, vector<bool> &x) {
    if (root == nullptr) return;
    if (root->op == 'x') x[root->id] = true;
    dfs(root->l, x);
    dfs(root->r, x);
}

shared_ptr<node> read(string &s, int &k, vector<bool> &x) {
    node u = {'x', false, nullptr, nullptr, 0};
    u.op = s[k++];
    if (u.op == 'x') {
        while (s[k] >= '0' && s[k] <= '9') {
            u.id = (u.id << 3) + (u.id << 1) + (s[k++] & 0xf);
        }
        u.v = x[u.id];
    }
    while (s[k] == ' ') ++k;
    return make_shared<node>(u);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<bool> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        bool a;
        cin >> a;
        x[i] = a;
    }
    stack<shared_ptr<node>> st;
    for (int i = 0; s[i];) {
        auto u = read(s, i, x);
        if (u->op == '!') {
            auto a = st.top();
            st.pop();
            u->v = !a->v;
            u->l = a;
        } else if (u->op == '&') {
            auto b = st.top();
            st.pop();
            auto a = st.top();
            st.pop();
            u->v = a->v && b->v;
            if ((!a->v && b->v) != u->v) u->l = a;
            if ((a->v && !b->v) != u->v) u->r = b;
        } else if (u->op == '|') {
            auto b = st.top();
            st.pop();
            auto a = st.top();
            st.pop();
            u->v = a->v || b->v;
            if ((!a->v || b->v) != u->v) u->l = a;
            if ((a->v || !b->v) != u->v) u->r = b;
        }
        st.push(u);
    }
    x.assign(n + 1, false);
    assert(st.size() == 1);
    auto root = st.top();
    dfs(root, x);
    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        cout << (x[i] ? !root->v : root->v) << '\n';
    }
    return 0;
}
