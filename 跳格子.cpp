#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
    int r, now;
} a[100001];
int n, m, i, ans[100001], min1, min2, k;
bool cmp(const info& shl, const info& shr) {
    return (shl.r > shr.r || shl.r == shr.r && shl.now < shr.now);
}
int main() {
    freopen("lattice.in", "r", stdin);
    freopen("lattice.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i].r);
        a[i].now = i, a[i].r += i;
    }
    sort(a + 1, a + 1 + n, cmp);
    min1 = min2 = 233333333;
    k = n + 1;
    for (i = 1; i <= n; i++) {
        if (a[i].r >= n + 1)
            ans[a[i].now] = 1, min1 = min(min1, a[i].now);
        else {
            k = i;
            break;
        }
    }
    for (i = k; i <= n; i++) {
        if (a[i].r >= min1)
            ans[a[i].now] = ans[min1] + 1, min2 = min(min2, a[i].now);
        else
            min1 = min2, min2 = a[i].now, ans[a[i].now] = ans[min1] + 1;
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &k);
        printf("%d ", ans[k]);
    }
}
/**
 * 题目：
 * 小H发明了一个跳格子的游戏，地板上画了排成一排的n个格子，并以1…n按顺序编号。他规定第i个格子可以跳到第1到第i-1个格子中的任一个，且每个格子有一个不一定相同的反方向的跳跃度a[i]，代表第i个格还可以跳到第i+1到i+a[i]个格子中的任一个。现在小H指定其中的一个格子，问从这个格子开始，最少需要连续踩几次格子（起始的格子也算在内），可以跳到第n个格子的后方，即若第k个格子有k+a[k]＞n，那么从第k个格子就可以跳到第n个格子的后方。
 * 题解：
 * 首先，我们定义一个结构体，包含格子的编号和跳跃度。然后，我们按照跳跃度从大到小排序，这样可以保证我们每次跳跃的格子都是可以跳到第n个格子后方的。
 * 然后，我们遍历每个格子，如果当前格子的跳跃度大于等于n，那么我们就从这个格子开始跳跃，否则我们就从这个格子开始跳跃，并且记录下这个格子的编号。
 * 最后，我们输出每个格子需要跳跃的次数。
 */
