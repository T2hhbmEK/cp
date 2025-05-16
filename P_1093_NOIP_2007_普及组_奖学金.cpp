#include <bits/stdc++.h>
#define maxn 310
using namespace std;

struct Stu {
    int score[4];
    int sum;
    int id;
} a[maxn];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i].score[j];
            a[i].sum += a[i].score[j];
        }
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, [](auto x, auto y) {
        if (x.sum != y.sum) return x.sum > y.sum;
        if (x.score[1] != y.score[1]) return x.score[1] > y.score[1];
        return x.id < y.id;
    });
    for (int i = 1; i <= n && i <= 5; i++) {
        cout << a[i].id << " " << a[i].sum << endl;
    }
    return 0;
}
