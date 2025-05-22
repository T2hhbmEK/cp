#include <bits/stdc++.h>
using namespace std;
const int N = 20 + 7;
int n;
string s[N];           // n 个字符串
char ch;               // 接龙的首字母
int vis[N];            // vis[i] 表示第 i 个字符串被使用的次数
int overlapMat[N][N];  // overlapMat[i][j] 表示 s[i] 和 s[j]
                       // 的最小重叠长度，不重叠时为 0
int a[N];              // 记录接龙的顺序
int sum, ans;
int match(int i, int j) {  // 计算 s[i] 和 s[j] 的最小重叠长度
    int sz1 = s[i].size();
    int sz2 = s[j].size();
    int szmin = min(sz1, sz2);
    for (int k = 1; k < szmin; ++k) {  // 不能存在包含关系，szmin 取不到
        if (s[i].substr(sz1 - k) == s[j].substr(0, k)) {  // 判断首位是否重叠
            return k;
        }
    }
    return 0;
}
void dfs(int k) {
    bool flag = 0;  // 是否可以继续接龙
    for (int i = 1; i <= n; ++i) {
        int overlap = overlapMat[a[k - 1]][i];  // 计算重叠长度
        // 1. vis[i] < 2 表示第 i 个字符串的使用次数小于 2
        // 2. overlap > 0 表示可以接龙
        // 3. k == 1 && s[i][0] == ch 表示第一个字符串的首字母为 ch
        if ((vis[i] < 2 && overlap > 0) || (k == 1 && s[i][0] == ch)) {
            a[k] = i;     // 记录接龙的顺序
            vis[i] += 1;  // 统计第 i 个字符串被使用的次数
            sum += s[i].size() - overlap;  // 更新 sum
            dfs(k + 1);                    // 继续接龙
            sum -= s[i].size() - overlap;  // 回溯
            vis[i] -= 1;                   // 回溯
            flag = 1;                      // 可以继续接龙
        }
    }
    if (flag == 0) {          // 无法继续接龙
        ans = max(ans, sum);  // 更新答案
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    cin >> ch;
    // 计算 overlapMat
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            overlapMat[i][j] = match(i, j);
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}
