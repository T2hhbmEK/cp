#include <bits/stdc++.h>
using namespace std;
map<string, int> a{
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"a", 1},
    {"both", 2},
    {"another", 1},
    {"first", 1},
    {"second", 2},
    {"third", 3}};
vector<int> b;
typedef long long ll;
ll ans;

void lower_case(string &s) {
    for (int i = 0; i <= s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A');
        }
    }
}
int main() {
    for (int i = 1; i <= 6; ++i) {
        string s;
        cin >> s;
        if (s == ".") {
            break;
        }
        // lower_case(s);
        if (a.find(s) != a.end()) {
            // cout << s << " " << a[s] << endl;
            b.push_back((a[s] * a[s]) % 100);
        }
    }
    sort(b.begin(), b.end());
    for (auto x : b) {
        ans *= 100;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}