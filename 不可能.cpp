#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
class Solution {
   public:
    const int MOD = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mL, mR;
        for (int i = 0; i < arr.size(); i++) {
            mR[arr[i]] = i;
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            mL[arr[i]] = i;
        }
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1, k = arr.size() - 1; j < k;) {
                if (arr[i] + arr[j] + arr[k] > target) {
                    k--;
                } else if (arr[i] + arr[j] + arr[k] < target) {
                    j++;
                } else {  // arr[i] + arr[j] + arr[k] == target
                    if (arr[j] != arr[k]) {
                        ans += (mR[arr[j]] - j + 1) * (k - mL[arr[k]] + 1);
                    } else {
                        ans += (k - j + 1) * (k - j) / 2;
                    }
                    j = mR[arr[j]] + 1;
                    k = mL[arr[k]] - 1;
                }
            }
        }
        return ans % MOD;
    }
};
void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol;
    ll ans = sol.threeSumMulti(a, t);
    ans = n * (n - 1) * (n - 2) / 6 - ans;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
