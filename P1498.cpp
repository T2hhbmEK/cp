#include <bits/stdc++.h>
using namespace std;
char t[2][5];
char o[1024][2050];
int n;

void _fill(int k) {
    int kk = pow(2, k);
    for (int i = 0; i < kk; ++i) {
        memset(o[i], ' ', kk * 2);
    }
}
void _strip(int k) {
    int kk = pow(2, k);
    for (int i = 0; i < kk; ++i) {
        int il = strlen(o[i]);
        int j = il - 1;
        while (o[i][j] == ' ') {
            o[i][j] = 0;
            j--;
        }
    }
}
void _print(int k) {
    int kk = pow(2, k);
    for (int i = 0; i < kk; ++i) {
        printf("%s\n", o[i]);
    }
}
void f(int i, int j, int k) {
    if (k == 1) {
        memcpy(o[i] + j, t[0], 4);
        memcpy(o[i + 1] + j, t[1], 4);
        return;
    }
    int kk = pow(2, k);
    f(i + kk / 2, j, k - 1);
    f(i + kk / 2, j + kk, k - 1);
    f(i, j + kk / 2, k - 1);
}
int main() {
    strcpy(t[0], " /\\ ");
    strcpy(t[1], "/__\\");
    scanf("%d", &n);
    _fill(n);
    f(0, 0, n);
    _strip(n);
    _print(n);
    return 0;
}