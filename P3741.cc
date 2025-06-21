#include <iostream>
#define maxn 105
using namespace std;

int n, cnt;
char s[maxn];
bool mask[maxn], flag;

int main() {
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'V' && s[i] == 'K') {
      mask[i - 1] = mask[i] = 1;
      cnt++;
      i++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (mask[i] == 0 && mask[i + 1] == 0 && s[i] == 'V') {
      flag = 1;
      break;
    }
  }
  for (int i = 1; i < n; i++) {
    if (mask[i - 1] == 0 && mask[i] == 0 && s[i] == 'K') {
      flag = 1;
      break;
    }
  }
  cout << cnt + flag << endl;
  return 0;
}
