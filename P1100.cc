#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  uint32_t a;
  cin >> a;
  a = (a << 16) | (a >> 16);
  cout << a << endl;
  return 0;
}
