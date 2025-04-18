#include <bits/stdc++.h>
using namespace std;

void print(list<list<int>> &b) {
    for (auto &x : b) {
        cout << "[";
        for (auto &y : x) {
            cout << y << ' ';
        }
        cout << "] ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    list<list<int>> b;
    b.push_back({1});
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[b.back().back()]) {
            b.push_back(list<int>());
        }
        b.back().push_back(i);
    }
    while (!b.empty()) {
        for (auto it = b.begin(); it != b.end(); ++it) {
            cout << it->front() << ' ';
            it->pop_front();
        }
        cout << '\n';
        for (auto it = b.begin(); it != b.end();) {  // remove empty list
            if (it->empty()) {
                it = b.erase(it);
            } else {
                ++it;
            }
        }
        for (auto it = b.begin(); it != b.end();) {  // merge list
            if (it != b.begin() && a[it->front()] == a[prev(it)->back()]) {
                prev(it)->splice(prev(it)->end(), *it);
                it = b.erase(it);
            } else {
                ++it;
            }
        }
    }
    return 0;
}
