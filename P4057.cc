#include <cstdint>
#include <iostream>
using namespace std;

template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int64_t a, b, c;
  cin >> a >> b >> c;
  cout << lcm(a, lcm(b, c)) << endl;
  return 0;
}
