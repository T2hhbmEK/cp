#include <bits/stdc++.h>
using namespace std;
#define N 10005
int n;
queue<int> q;
int main() {
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int j, x;
        scanf("%d", &j);
        if (j == 1) {
            scanf("%d", &x);
        }
        switch (j) {
            case 1:
                q.push(x);
                break;
            case 2:
                if (!q.empty()) {
                    q.pop();
                } else {
                    printf("ERR_CANNOT_POP\n");
                }
                break;
            case 3:
                if (!q.empty()) {
                    printf("%d\n", q.front());
                } else {
                    printf("ERR_CANNOT_QUERY\n");
                }
                break;
            default:  // 4
                printf("%d\n", q.size());
                break;
        }
    }
    return 0;
}