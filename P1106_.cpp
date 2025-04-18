#include <bits/stdc++.h>
using namespace std;
#define N 255
int k, nl;
char s[N], f[10];
list<int> n, ans;
void _pf() {
    for (int i = 0; i <= 9; ++i) {
        printf("%d ", f[i]);
    }
    printf("\n");
}
void _p(list<int> n) {
    for (int i = 0; i < n.size(); ++i) {
        printf("%d", n.front());
        n.push_back(n.front());
        n.pop_front();
    }
    printf("\n");
}
int main() {
    scanf("%s%d", s, &k);
    nl = strlen(s);
    for (int i = 1; i <= nl; ++i) {
        int x = s[i - 1] - '0';
        if (f[x] == 0 && i <= k + 1) {  // skip if cannot be prefix
            f[x] = i;                   // index of first 0-9
        }
        n.push_back(x);
    }
    if (nl - k == 1 && f[0] > 0) {  // special case 0
        printf("0\n");
        return 0;
    }
    nl -= k;
    int p = 0;
    for (int i = 1; i <= 9 && p == 0; ++i) {
        if (f[i] > 0) {
            p = i;
            for (int j = 1; j <= f[i]; ++j) {
                n.pop_front();
                k--;
            }
        }
    }
    k++;  // prefix
    while (!n.empty()) {
        while (!ans.empty() && ans.back() > n.front() && k > 0) {
            ans.pop_back();
            k--;
        }
        ans.push_back(n.front());
        n.pop_front();
    }
    ans.push_front(p);
    for (int i = 0; i < nl; ++i) {
        printf("%d", ans.front());
        ans.pop_front();
    }
    printf("\n");
    return 0;
}