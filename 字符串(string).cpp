/* 思路：
 * 回文串头尾相同，有 s[0] == s[n-1]
 * 又字符串旋转之后是回文串，有 s[i+1] == s[i] 其中 i = 0, 2, ..., n-1
 * 所以字符串需要所有字符相同 s[0] == s[1] == ... == s[n-1]
 * 修改次数 = n - 最多字符出现次数
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int t, cnt[26];  // t 表示测试用例数量，cnt 用于记录每个字符出现的次数
string s;  // 存储输入字符串

void solve() {
    cin >> s;                     // 读入字符串并获取长度
    int n = s.length();           // 获取字符串长度
    memset(cnt, 0, sizeof(cnt));  // 重置字符计数数组为 0
    for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];  // 统计每个字符出现的次数
    int ans = 0;  // 找到出现次数最多的字符
    for (int i = 0; i < 26; ++i) ans = max(ans, cnt[i]);
    cout << n - ans << endl;  // 输出需要修改的次数
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);  // 加速输入输出流
    cin >> t;                             // 读入测试用例数量
    while (t--) solve();                  // 处理每个测试用例
    return 0;
}
