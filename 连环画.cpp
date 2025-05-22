#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = unique(a.begin(), a.end()) - a.begin();
    list<int> s(a.begin(), a.end());
    int ans = 0;
    while (s.size() > 1) {
        if (s.front() == ans + 1) {
            s.pop_front();
            s.push_back(++ans);
        } else {
            s.pop_back();
            s.pop_back();
            s.push_back(++ans);
        }
    }
    if (s.front() == ans + 1) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
