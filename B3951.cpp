#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, a[N], m, x;
int s[N], top;

int f() {
    cin >> x;
    s[top++] = a[x];
    int ans = 0;
    int i = top - 1;
    while (i - 1 >= 0 && s[i - 1] > s[i]) {
        int j = i - 1;
        while (j - 1 >= 0 && s[j - 1] == s[j]) j--;
        swap(s[i], s[j]), i = j, ans++;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    while (m--) {
        cout << f() << '\n';
    }
    return 0;
}
