#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e5 + 5;

struct Student {
    string name;
    int score[4];
    void total() { score[0] = score[1] + score[2] + score[3]; }
    void read() {
        cin >> name;
        for (int i = 1; i <= 3; i++) {
            cin >> score[i];
        }
    }
    void print() {
        cout << name << " ";
        for (int i = 1; i <= 3; i++) {
            cout << score[i] << " ";
        }
        cout << endl;
    }
} a[NMAX];
int n;

bool cmp(Student a, Student b) { return a.score[0] > b.score[0]; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].read();
        a[i].total();
    }
    stable_sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        a[i].print();
    }
    return 0;
}
