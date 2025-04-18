#include <bits/stdc++.h>
using namespace std;
#define N 105
unsigned int s[N], n, x;
int main() {
    x = 1;
    do {
        scanf("%u", &x);
        s[n++] = x;
    } while (x != 0);
    --n;
    while (n > 0) {
        printf("%u ", s[--n]);
    }
    printf("\n");
    return 0;
}