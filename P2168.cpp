// huffman tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll w;
    vector<shared_ptr<node>> ch;
    ll d;
    ll id;
    explicit node() : w(0), d(0) {
        static ll cnt = 0;
        id = ++cnt;
    }
};
struct cmp {
    bool operator()(const shared_ptr<node> &x, const shared_ptr<node> &y) {
        if (x->w == y->w) {
            return x->d > y->d;
        }
        return x->w > y->w;
    }
};
void p(const shared_ptr<node> &x) {
    printf("%lld(%lld,%lld)", x->id, x->w, x->d);
}
void bfs(const shared_ptr<node> rt) {
    ll ans = 0;
    queue<shared_ptr<node>> q;
    q.push(rt);
    while (!q.empty()) {
        const shared_ptr<node> rt = q.front();
        q.pop();
        if (rt->ch.size() > 0) {
            ans += rt->w;
        }
        for (const shared_ptr<node> x : rt->ch) {
            q.push(x);
        }
    }
    cout << ans << endl;
}
int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<shared_ptr<node>, vector<shared_ptr<node>>, cmp> pq;
    for (int i = 1; i <= n; ++i) {
        const shared_ptr<node> &a = make_shared<node>();
        scanf("%lld", &(a->w));
        pq.push(a);
    }
    while ((pq.size() - 1) % (k - 1) != 0) pq.push(make_shared<node>());
    while (pq.size() >= k) {
        const shared_ptr<node> &c = make_shared<node>();
        for (int i = 1; i <= k; ++i) {
            // don't use reference of top element
            // or it will always ref to top element after pop
            const shared_ptr<node> a = pq.top();
            pq.pop();
            c->w += a->w;
            c->ch.push_back(a);
            c->d = max(c->d, a->d + 1);
        }
        pq.push(c);
    }
    bfs(pq.top());
    cout << pq.top()->d << endl;
    return 0;
}
