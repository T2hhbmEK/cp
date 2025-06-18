#include <iomanip>
#include <iostream>
#define maxn 16
using namespace std;
int n, a[maxn][maxn];
int dx[4] = {0, 1, 0, -1};  // right, down, left, up
int dy[4] = {1, 0, -1, 0};
int main() {
    cin >> n;
    for (int k = 1, i = 1, j = 1, d = 0; k <= n * n; k++) {
        a[i][j] = k;
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] != 0) {
            d = (d + 1) % 4;
            nx = i + dx[d];
            ny = j + dy[d];
        }
        i = nx;
        j = ny;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
