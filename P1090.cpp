#include <bits/stdc++.h>
using namespace std;
#define N 10005
int n, a[N], ans;
void pr() {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("ans=%d\n", ans);
}
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    make_heap(a, a + n, cmp);
    while (n > 1) {
        pop_heap(a, a + n--, cmp);
        pop_heap(a, a + n, cmp);
        a[n - 1] += a[n];
        ans += a[n - 1];
        push_heap(a, a + n, cmp);
    }
    cout << ans << endl;
    return 0;
}