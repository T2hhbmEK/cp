#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n;
list<int> dq[N];
char op[20];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", op);
        int a, x;
        if (strcmp(op, "push_back") == 0) {
            scanf("%d%d", &a, &x);
            dq[a].push_back(x);
        } else if (strcmp(op, "pop_back") == 0) {
            scanf("%d", &a);
            if (!dq[a].empty()) {
                dq[a].pop_back();
            }
        } else if (strcmp(op, "push_front") == 0) {
            scanf("%d%d", &a, &x);
            dq[a].push_front(x);
        } else if (strcmp(op, "pop_front") == 0) {
            scanf("%d", &a);
            if (!dq[a].empty()) {
                dq[a].pop_front();
            }
        } else if (strcmp(op, "size") == 0) {
            scanf("%d", &a);
            printf("%d\n", dq[a].size());
        } else if (strcmp(op, "front") == 0) {
            scanf("%d", &a);
            if (!dq[a].empty()) {
                printf("%d\n", dq[a].front());
            }
        } else if (strcmp(op, "back") == 0) {
            scanf("%d", &a);
            if (!dq[a].empty()) {
                printf("%d\n", dq[a].back());
            }
        }
    }
    return 0;
}