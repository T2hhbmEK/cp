#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 120
using namespace std;

struct Info {
    string na, pos;
    int exp, rnk, id;
} a[maxn];
int n;
string aPos[10] = {
    "",         "BangZhu", "FuBangZhu", "HuFa",
    "ZhangLao", "TangZhu", "JingYing",  "BangZhong",
};
int cnt[10] = {0, 1, 2, 2, 4, 7, 25, inf};
unordered_map<string, int> mpPos = {
    {"BangZhu", 1},    //
    {"FuBangZhu", 2},  //
    {"HuFa", 3},       //
    {"ZhangLao", 4},   //
    {"TangZhu", 5},    //
    {"JingYing", 6},   //
    {"BangZhong", 7},  //
};
string na_self = "absi2011";

bool cmp1(Info x, Info y) {
    if (x.exp != y.exp) return x.exp > y.exp;
    return x.id < y.id;
}

bool cmp2(Info x, Info y) {
    if (x.pos != y.pos) return mpPos[x.pos] < mpPos[y.pos];
    if (x.rnk != y.rnk) return x.rnk > y.rnk;
    return x.id < y.id;
}

void prt() {
    for (int i = 1; i <= n; i++) {
        cout << a[i].na << " ";
        cout << a[i].pos << " ";
        // cout << a[i].exp << " ";
        cout << a[i].rnk << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].na;
        cin >> a[i].pos;
        cin >> a[i].exp;
        cin >> a[i].rnk;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    for (int i = 1; i <= n; i++) {
        if (a[i].pos == "BangZhu" || a[i].pos == "FuBangZhu" ||
            a[i].na == na_self) {
            cnt[mpPos[a[i].pos]]--;
        }
    }
    for (int i = 1, j = 1; i <= n; i++) {
        if (a[i].pos == "BangZhu" || a[i].pos == "FuBangZhu" ||
            a[i].na == na_self) {
            continue;
        }
        while (cnt[j] <= 0) j++;
        a[i].pos = aPos[j];
        cnt[j]--;
    }
    sort(a + 1, a + 1 + n, cmp2);
    prt();
    return 0;
}
