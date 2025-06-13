#include <bits/stdc++.h>
#define int long long
#define maxn 40
using namespace std;

string s;
int N, len;

int f(int n) {
    if (n < len) return n;
    int hf = len;
    while (hf <= n) hf <<= 1;
    hf >>= 1;
    return f((n - 1) % hf);
}

signed main() {
    cin >> s >> N;
    len = s.size();
    cout << s[f(N - 1)] << endl;
    return 0;
}
