#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
unordered_map<char, int> mCh2I = {
    {'A', 2},
    {'B', 2},
    {'C', 2},
    {'D', 3},
    {'E', 3},
    {'F', 3},
    {'G', 4},
    {'H', 4},
    {'I', 4},
    {'J', 5},
    {'K', 5},
    {'L', 5},
    {'M', 6},
    {'N', 6},
    {'O', 6},
    {'P', 7},
    {'R', 7},
    {'S', 7},
    {'T', 8},
    {'U', 8},
    {'V', 8},
    {'W', 9},
    {'X', 9},
    {'Y', 9},
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (auto const &c : s) {
        a.push_back(c - '0');
    }
    bool nFound = true;
    while (cin >> s) {
        bool isValid = s.size() == a.size();
        if (!isValid) continue;
        for (int i = 0; i < s.size(); ++i) {
            if (mCh2I[s[i]] != a[i]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            nFound = false;
            cout << s << '\n';
        }
    }
    if (nFound) cout << "NONE\n";
    return 0;
}