#include <bits/stdc++.h>
using namespace std;

int main() {
    double t;
    cin >> t;
    if (t >= 39) {
        cout << "red";
    } else if (t >= 37) {
        cout << "orange";
    } else if (t >= 35) {
        cout << "yellow";
    } else {
        cout << "null";
    }
    return 0;
}

/*
数轴表示区间
实心、空心圆圈表示能否取等号
     ------------------->
    |      ------------->
    |     |      ------->
 nul| yel | ora | red
----x-----x-----x------->
    35    37    39
多分支语句，后续分支隐含条件：之前分支不成立

如果不熟练，可以把隐含的条件写全
注意!(a<b)是a>=b不是a>b
*/