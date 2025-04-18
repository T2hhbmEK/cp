#include <bits/stdc++.h>
using namespace std;
#define N 105

int n, a[N][N], in[N];
queue<int> q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int j = 0;
        do {
            scanf("%d", &a[i][++j]);
            in[a[i][j]]++;
        } while (a[i][j] != 0);
        a[i][0] = j - 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        printf("%d ", i);
        for (int j = 1; j <= a[i][0]; ++j) {
            int i2 = a[i][j];
            in[i2]--;
            if (in[i2] == 0) {
                q.push(i2);
            }
        }
    }
    printf("\n");
    return 0;
}