#include <bits/stdc++.h>
using namespace std;
#define N 1000005
typedef unsigned long long llu;
llu st[N], x;
int T, n, sz;
char tmp[50];
void _print() {
    for (int i = 0; i <= sz; ++i) {
        printf("%llu ", st[i]);
    }
    printf("\n");
}
void _purge() { sz = 0; }
void _push(llu x) {
    st[++sz] = x;
}
void _pop() {
    if (sz == 0) {
        printf("Empty\n");
        return;
    }
    sz--;
}
void _query() {
    if (sz == 0) {
        printf("Anguei!\n");
        return;
    }
    printf("%llu\n", st[sz]);
}
void _size() {
    printf("%llu\n", sz);
}
int main() {
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        scanf("%d", &n);
        for (int j = 1; j <= n; ++j) {
            scanf("%s", tmp);
            if (strcmp(tmp, "push") == 0) {
                scanf("%llu", &x);
                _push(x);
            }
            if (strcmp(tmp, "pop") == 0) {
                _pop();
            }
            if (strcmp(tmp, "query") == 0) {
                _query();
            }
            if (strcmp(tmp, "size") == 0) {
                _size();
            }
        }
        _purge();
    }
    return 0;
}