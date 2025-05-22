#include <bits/stdc++.h>
using namespace std;

// 初始化
const int m = 1001;  // 最多1000个元素
int q[m];
int front = 0, rear = 0;

// 判空
int empty() {
    return front == rear;
}

// 判满
int full() {
    // 留出一个位置用于区分队列满和空
    return (rear + 1) % m == front;
}

// 入队
void push(int x) {
    // 如果队列已满则不能入队
    if (full()) return;
    q[rear] = x;
    rear = (rear + 1) % m;  // 循环处理rear
}

// 出队
int pop() {
    if (empty()) return -1;  // 如果队列为空则返回-1
    int ret = q[front];
    front = (front + 1) % m;  // 循环处理front
    return ret;
}

// 元素个数
int size() {
    return (rear - front + m) % m;
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
