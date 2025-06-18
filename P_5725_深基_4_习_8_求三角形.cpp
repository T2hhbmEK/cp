#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, k = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%02d", k++);
        putchar('\n');
    }
    putchar('\n');
    for (int i = 1, k = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf("  ");
        for (int j = n - i + 1; j <= n; j++) printf("%02d", k++);
        putchar('\n');
    }
    return 0;
}
