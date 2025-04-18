#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 105;

struct Patient {
    int id, age;
    bool is_old() { return age >= 60; }
} a[maxn];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].age;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].is_old()) {
            cout << a[i].id << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!a[i].is_old()) {
            cout << a[i].id << endl;
        }
    }
    return 0;
}
