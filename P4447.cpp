#include <bits/stdc++.h>
using namespace std;
#define N 100005
int a[N], n, cc[N];
void _p(int a[N], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int j = 1;
    cc[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++cc[j - 1];
        } else {
            ++cc[j];
            a[j++] = a[i];
        }
    }
    n = j;
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        while (cc[i] > 0) {
            int x = 1;
            for (int j = i + 1;
                 j < n && cc[j] > 0 &&
                 a[j] - a[j - 1] == 1 && cc[j] >= cc[j - 1];
                 ++j) {
                ++x;
            }
            for (int j = i; j < i + x; ++j) {
                --cc[j];
            }
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}