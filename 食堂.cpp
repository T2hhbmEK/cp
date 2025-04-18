#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, R, V, M;
    cin >> a >> b >> R >> V >> M;
    cout << R * b + 2 * R * 2 * a << " ";
    cout << V * b + 3 * V * 2 * a << " ";
    cout << M * b + 3 * M * 2 * a;
    return 0;
}

/*
一次用餐需要的量 * 用餐次数 * 人数
学生和老师分别计算之后相加
注意变量名和题面相同，不容易出错
注意输出格式，用空格而不是换行
输出太长可以分多次
*/