#include <bits/stdc++.h>
using namespace std;

// 初始化
const int m = 1005;
int q[m];
int front = 0, rear = 0;

// 判空
int empty() {
    return front == rear;
}

// 判满
int full() {
    return rear == m;
}

// 入队
void push(int x) {
    if (full()) return;  // 如果队列已满则不能入队
    q[rear++] = x;
}

// 出队
int pop() {
    if (empty()) return -1;  // 如果队列为空则返回-1
    return q[front++];
}

// 元素个数
int size() {
    return rear - front;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        push(a);  // 入队
    }

    while (!empty()) {  // 输出队列内所有元素
        printf("%d ", pop());
    }
    return 0;
}
