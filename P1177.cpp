#include <bits/stdc++.h>
using namespace std;

#define N 100005
int n, a[N];

void _qsort(int* a, int fst, int lst) {
    if (fst >= lst) {
        return;
    }
    int l = fst;
    int r = lst - 1;
    int mid = a[lst];
    while (l <= r) {
        while (l <= r && a[l] < mid) {
            ++l;
        }
        while (l <= r && a[r] >= mid) {
            --r;
        }
        if (l < r) {
            swap(a[l], a[r]);
        }
    }
    swap(a[l], a[lst]);
    _qsort(a, fst, l - 1);
    _qsort(a, l + 1, lst);
}

void _qsort3(int* a, int fst, int lst) {
    if (fst >= lst) {
        return;
    }
    int l = fst;
    int r = lst;
    int i = l;
    int mid = a[(fst + lst) / 2];
    while (i <= r) {
        if (a[i] < mid) {
            swap(a[l++], a[i++]);
        } else if (a[i] > mid) {
            swap(a[r--], a[i]);
        } else {
            ++i;
        }
    }
    _qsort3(a, fst, l - 1);
    _qsort3(a, r + 1, lst);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // sort(a, a + n);
    _qsort3(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}