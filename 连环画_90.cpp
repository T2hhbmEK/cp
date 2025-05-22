#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n;

void show() {
    int sz = q.size();
    while (sz--) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main() {
    cin >> n;
    int lj = 0;  // 垃圾
    while (n--) {
        int a;
        cin >> a;
        if (!q.empty() && q.back() == a) {
            lj += 1;  // 重复的书变成垃圾
        } else {
            q.push(a);
        }
    }
    int i = 1;
    int qlj = 0;  // q末尾已经被换掉的书的个数
    while (q.size() - qlj > 0) {
        int a = q.front();
        if (a == i) {
            q.pop();
        } else {
            if (lj >= 2) {
                lj -= 2;  // 两本垃圾换一本i
            } else if (lj == 1) {
                lj -= 1;   // 一本垃圾
                qlj += 1;  // 和一本书换一本i
            } else {
                qlj += 2;  // 两本书换一本i
            }
        }
        lj += 1;  // i看完变成垃圾
        // printf("read %d, lj=%d, qlj=%d\n", i, lj, qlj);
        // show();
        i += 1;
    }
    cout << i - 1 + lj - 1; // 最后剩下 lj 可以换 lj-1 本书看
    return 0;
}