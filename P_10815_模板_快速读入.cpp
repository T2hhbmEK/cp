#include <bits/stdc++.h>
using namespace std;

constexpr int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                                 \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
         ? EOF                                                               \
         : *p1++)

#define getchar gc
// #define getchar getchar_unlocked

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch & 0xf);
        ch = getchar();
    }
    return x * f;
}

void solve_read() {
    int n = read(), ans = 0;
    for (int i = 0; i < n; i++) {
        ans += read();
    }
    printf("%d", ans);
}

void solve_scanf() {
    int n, x, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ans += x;
    }
    printf("%d", ans);
}

void solve_cin() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans += x;
    }
    cout << ans;
}

int main() {
    solve_read();
    return 0;
}
