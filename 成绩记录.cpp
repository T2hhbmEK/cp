#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct student {
    int id, chinese, math, english, st;
    void input() { cin >> id >> chinese >> math >> english >> st; }
    double getSum() { return (chinese + math + english) * 0.7 + st * 0.3; }
    bool isExcellent() { return getSum() >= 200; }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        student t;
        t.input();
        cout << fixed << setprecision(1) << t.getSum();
        if (t.isExcellent()) cout << " " << t.id;
        cout << endl;
    }
    return 0;
}
