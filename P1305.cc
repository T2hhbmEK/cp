#include <iostream>
#define maxn 256
using namespace std;
char c, ch[maxn][2];
void preOrder(char rt) {
  if (rt == '*') return;
  cout << rt;
  preOrder(ch[(int)rt][0]);
  preOrder(ch[(int)rt][1]);
}
int main() {
  int n;
  cin >> n;
  char rt = '*';
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    if (rt == '*') rt = c;
    cin >> ch[(int)c][0] >> ch[(int)c][1];
  }
  preOrder(rt);
  cout << endl;
  return 0;
}
