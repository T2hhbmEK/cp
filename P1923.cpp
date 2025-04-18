#include <bits/stdc++.h>
using namespace std;

#define N 5000005
int n, k, a[N];

void _nth_element3(int* a, int fst, int lst, int k) {
    int l = fst;
    int r = lst;
    int i = l;
    // printf("%d\n", fst + rand() % (lst - fst + 1));
    // int mid = a[(fst + lst) / 2];
    int mid = a[fst + rand() % (lst - fst + 1)];
    while (i <= r) {
        if (a[i] < mid) {
            swap(a[i++], a[l++]);
        } else if (a[i] > mid) {
            swap(a[i], a[r--]);
        } else {
            i++;
        }
    }
    if (k < l) {
        _nth_element3(a, fst, l - 1, k);
    }
    if (k > r) {
        _nth_element3(a, r + 1, lst, k);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    _nth_element3(a, 0, n - 1, k);
    printf("%d\n", a[k]);
    return 0;
}