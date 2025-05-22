#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int a[100000][15], ans;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i1 = 1; i1 <= 3; i1++)
    for (int i2 = 1; i2 <= 3; i2++)
    for (int i3 = 1; i3 <= 3; i3++)
    for (int i4 = 1; i4 <= 3; i4++)
    for (int i5 = 1; i5 <= 3; i5++)
    for (int i6 = 1; i6 <= 3; i6++)
    for (int i7 = 1; i7 <= 3; i7++)
    for (int i8 = 1; i8 <= 3; i8++)
    for (int i9 = 1; i9 <= 3; i9++)
    for (int i10 = 1; i10 <= 3; i10++) {
        if (i1+i2+i3+i4+i5+i6+i7+i8+i9+i10==n){
            ans++;
            a[ans][1]=i1;
            a[ans][2]=i2;
            a[ans][3]=i3;
            a[ans][4]=i4;
            a[ans][5]=i5;
            a[ans][6]=i6;
            a[ans][7]=i7;
            a[ans][8]=i8;
            a[ans][9]=i9;
            a[ans][10]=i10;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        for (int j = 1; j<= 10; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
