#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define assert(x)
const int MAXN = 1e5 + 10;
const int TEN = 10;
using vi = vector<int>;
using vii = vector<vi>;

int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

struct NUM {
    int a[TEN];
    int sz;
    NUM() : sz(0) {
        memset(a, 0, sizeof a);
    }
    int fst() {
        assert(!empty());
        int b = 1;  // first digit
        while (a[b] == 0) b++;
        assert(b < TEN);
        return b;
    }
    string to_s() {
        if (empty()) return "-1";
        int b = fst();
        string s;
        s += to_string(b), a[b]--;
        for (int i = 0; i < TEN; i++) {
            for (int j = 1; j <= a[i]; j++) s += to_string(i);
        }
        a[b]++;
        return s;
    }
    void add(int x) {
        assert(x != 0 || !empty());
        a[x]++, sz++;
    }
    void del(int x) {
        assert(a[x] > 0);
        a[x]--, sz--;
    }
    int cnt(int x) {
        return a[x];
    }
    bool empty() {
        return a[0] == sz;
    }
} f[MAXN];

int cmp(NUM a, NUM b) {
    assert(!a.empty() && !b.empty());
    if (a.sz != b.sz) return a.sz - b.sz;
    int af = a.fst(), bf = b.fst();
    if (af != bf) return af - bf;
    for (int i = 0; i < TEN; i++) {
        if (a.cnt(i) != b.cnt(i)) return b.cnt(i) - a.cnt(i);
    }
    return 0;
}

void pre(int n) {
    for (int i = 1; i <= n; i++) {
        int k = i - cnt[8];
        if (k > 0 && f[k].cnt(8) > 0) {
            f[i] = f[k];
            f[i].add(8);
            continue;
        }
        for (int j = 0; j < TEN; j++) {
            NUM tmp;
            int k = i - cnt[j];
            if (k == 0 && j != 0) {
                tmp.add(j);
            } else if (k > 0 && !f[k].empty()) {
                tmp = f[k];
                tmp.add(j);
            }
            if (!tmp.empty()) {
                if (f[i].empty() || cmp(f[i], tmp) > 0) {
                    f[i] = tmp;
                }
            }
        }
    }
}

int main() {
    pre(1e5);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f[n].to_s() << endl;
    }
    return 0;
}
