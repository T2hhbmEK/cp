#include <bits/stdc++.h>
using namespace std;
#define N 255
int k, nl;
char s[N];
list<int> n, ans;
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
        n.push_back(s[i - 1] - '0');
    }
    nl -= k;
    while (!n.empty()) {
        while (!ans.empty() && ans.back() > n.front() && k > 0) {
            ans.pop_back();
            k--;
        }
        ans.push_back(n.front());
        n.pop_front();
    }
    while (nl > 1 && ans.front() == 0) {
        ans.pop_front();
        nl--;
    }
    for (int i = 0; i < nl; ++i) {
        printf("%d", ans.front());
        ans.pop_front();
    }
    printf("\n");
    return 0;
}