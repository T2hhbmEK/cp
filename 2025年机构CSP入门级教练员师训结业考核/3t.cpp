#include <bits/stdc++.h>
#define maxn 55
#define maxv 1005
using namespace std;

int n;
int a[maxv][maxv];

inline int randint(int a, int b) {
    return rand() % (b - a) + a;
}

int main() {
    srand(1);
    n = randint(1, 50);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int x = randint(1, 1000);
        int y = randint(1, 1000);
        a[x][y] = i;
        cout << x << " " << y << endl;
    }
    int k = 0;
    return 0;
}
