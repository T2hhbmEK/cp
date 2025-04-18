#include <bits/stdc++.h>
using namespace std;

struct node {
    bool value;
    int skip_and;
    int skip_or;
};

node calc(node& a, node& b, char op) {
    // 计算两个节点之间的逻辑运算结果，并返回一个新的节点
    node c = {0, 0, 0};
    if (op == '&') {
        c.value = a.value && b.value;
        if (a.value == 0) {
            c.skip_and = a.skip_and + 1;
            c.skip_or = a.skip_or;
        } else {
            c.skip_and = a.skip_and + b.skip_and;
            c.skip_or = a.skip_or + b.skip_or;
        }
    } else if (op == '|') {
        c.value = a.value || b.value;
        if (a.value == 1) {
            c.skip_and = a.skip_and;
            c.skip_or = a.skip_or + 1;
        } else {
            c.skip_and = a.skip_and + b.skip_and;
            c.skip_or = a.skip_or + b.skip_or;
        }
    }
    return c;
}

void popnpush(stack<node>& ns, stack<char>& os) {
    // 从数字栈中弹出两个数字，从操作符栈中弹出一个操作符，进行计算，将结果压回数字栈
    node b = ns.top();
    ns.pop();
    node a = ns.top();
    ns.pop();
    char op = os.top();
    os.pop();
    ns.push(calc(a, b, op));
}

int main() {
    string s;
    cin >> s;
    stack<node> ns;                                            // 数字栈
    stack<char> os;                                            // 操作符栈
    map<char, int> priority = {{'(', 0}, {'|', 1}, {'&', 2}};  // 操作符优先级
    for (char ch : s) {
        if (ch == '0' || ch == '1') {
            ns.push((node){ch - '0', 0, 0});
        } else if (ch == '&' || ch == '|') {
            while (!os.empty() && priority[os.top()] >= priority[ch]) {
                popnpush(ns, os);
            }
            os.push(ch);
        } else if (ch == '(') {
            os.push(ch);
        } else if (ch == ')') {
            while (os.top() != '(') {
                popnpush(ns, os);
            }
            os.pop();
        }
    }
    while (!os.empty()) {
        popnpush(ns, os);
    }
    cout << ns.top().value << '\n';
    cout << ns.top().skip_and << ' ' << ns.top().skip_or << '\n';
    return 0;
}
