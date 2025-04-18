#include <bits/stdc++.h>
using namespace std;
#define N 21

int n;
char m[N][105];

bool cmp(char* x, char* y) {
    int xl = strlen(x);
    int yl = strlen(y);
    if (xl != yl) {
        return xl > yl;
    }
    return strcmp(x, y) > 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", m[i]);
    }
    int max_i = 1;
    for (int i = 2; i <= n; ++i) {
        if (cmp(m[i], m[max_i])) {
            max_i = i;
        }
    }
    printf("%d\n%s\n", max_i, m[max_i]);
    return 0;
}