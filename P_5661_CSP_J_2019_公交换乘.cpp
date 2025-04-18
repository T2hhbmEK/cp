#include <bits/stdc++.h>
using namespace std;

struct Ticket {
    int price;
    int time;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    list<Ticket> q;
    int ans = 0;
    while (n--) {
        Ticket t;
        int type;
        cin >> type >> t.price >> t.time;
        if (type == 0) {
            q.push_back(t);
            ans += t.price;
            continue;
        }
        while (!q.empty() && q.front().time < t.time - 45) {
            q.pop_front();
        }
        auto it = q.begin();
        while (it != q.end() && it->price < t.price) {
            ++it;
        }
        if (it == q.end()) {
            ans += t.price;
        } else {
            q.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}
