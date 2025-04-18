#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

bool cmp(const point& a, const point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<point> ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].x >> ps[i].y;
    }
    sort(ps.begin(), ps.end(), cmp);
    vector<vector<int>> dp(n, vector<int>(k + 1));
    // dp[i][j] 表示以第 i 个点为结尾，自由添加点数为 j 的方案数
    // 初始化 dp[i][j] = 1 + j
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 1 + j;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (ps[i].x >= ps[j].x && ps[i].y >= ps[j].y) {
                int d = ps[i].x - ps[j].x + ps[i].y - ps[j].y;
                for (int l = d - 1; l <= k; ++l) {
                    dp[i][l] = max(dp[i][l], dp[j][l - d + 1] + d);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i][k]);
    }
    cout << ans << '\n';
    return 0;
}
