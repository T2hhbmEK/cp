#include <bits/stdc++.h>
using namespace std;
namespace P7055 {
#define endl '\n'
typedef long long ll;
const int N = 1E3 + 5;
int n;
string s;
unordered_map<ll, vector<string>> d;
int hs(const string& s) {
    int a = 0;
    for (const char& c : s) {
        a *= 31;
        a += c;
    }
    return a;
}
ll hss(const string& s) {
    return (static_cast<ll>(hs(s)) << 32) + s.size();
}
void nxt(string& s) {
    int a = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (a == 0) break;
        a = 0;
        switch (s[i]) {
            case 'Z':
                s[i] = 'a';
                break;
            case 'z':
                s[i] = 'A', a = 1;
                break;
            default:
                ++s[i];
                break;
        }
    }
    if (a) {
        // for (const char& c : s) assert(c == 'A');
        s += 'A';
    }
}
int cnt() {
    int a = 1;
    vector<ll> t;
    vector<int> sum;
    for (const auto& [k, v] : d) {
        if (v.size() > 1) t.push_back(k);
        sum.push_back(sum.size() ? sum.back() : 0 + (k << 32 >> 32));
    }
    sort(t.begin(), t.end(), greater<int>{});
    for (int i = 0; i < t.size() && sum[i] < 1000; ++i) {
        ll k = t[i];
        a *= d[k].size();
    }
    return a;
}
void gen(int n) {
    vector<vector<string>> a;
    int cnt = 1;
    for (const auto& [k, v] : d) {
        if (v.size() > 1) a.emplace_back(v);
        cnt *= v.size();
        if (cnt > n) break;
    }
    for (int i = 0; i < n; ++i) {
        int x = i;
        string s;
        for (int j = 0; j < a.size(); ++j) {
            int k = x % a[j].size();
            s += a[j][k];
            x /= a[j].size();
        }
        cout << s << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    s = "AA";
    while (s.size() < 3) {
        d[hss(s)].push_back(s);
        nxt(s);
    }
    gen(n);
    return 0;
}
}  // namespace P7055
int main() {
    return P7055::main();
}