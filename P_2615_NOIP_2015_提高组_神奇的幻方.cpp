#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    int n;
    cin >> n;
    vii a(n, vi(n, 0));
    for (int k = 1, i = 0, j = (n - 1) / 2; k <= n * n; k++) {
        a[i][j] = k;
        int ni = (i - 1 + n) % n, nj = (j + 1) % n;
        if (a[ni][nj] != 0) ni = (i + 1) % n, nj = j;
        i = ni, j = nj;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
