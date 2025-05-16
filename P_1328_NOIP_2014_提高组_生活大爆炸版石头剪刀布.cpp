#include <bits/stdc++.h>
#define maxn 210
using namespace std;

int n, na, nb, sa, sb;
int a[maxn], b[maxn];
int s[5][5] = {
    {0, -1, 1, 1, -1},  //
    {0, 0, -1, 1, -1},  //
    {0, 0, 0, -1, 1},   //
    {0, 0, 0, 0, 1},    //
    {0, 0, 0, 0, 0},    //
};

void init() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            s[i][j] = -s[j][i];
        }
    }
}

int main() {
    init();
    cin >> n >> na >> nb;
    for (int i = 0; i < na; ++i) cin >> a[i];
    for (int i = 0; i < nb; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        int res = s[a[i % na]][b[i % nb]];
        if (res > 0) ++sa;
        if (res < 0) ++sb;
    }
    cout << sa << " " << sb << endl;
    return 0;
}
