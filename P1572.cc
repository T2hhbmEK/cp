#include <cassert>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using i32 = int;
using i64 = long long;

i64 gcd(i64 a, i64 b) { return b == 0 ? a : gcd(b, a % b); }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

struct Fraction {
  i64 sign, num, den;
  Fraction() = delete;
  Fraction(int x) : sign(x < 0 ? -1 : 1), num(abs(x)), den(1) {}
  Fraction& Simplify() {
    assert(den != 0);
    if (num == 0) {
      sign = 1, num = 0, den = 1;
      return *this;
    }
    i64 g = gcd(num, den);
    num /= g;
    den /= g;
    sign = sign * num / abs(num) * den / abs(den);
    num = abs(num);
    den = abs(den);
    return *this;
  }
};

istream& operator>>(istream& is, Fraction& x) {
  x.sign = 1, x.num = 0, x.den = 0;
  char c = 0;
  if (cin >> c && c == '-') x.sign = -1;
  if (isdigit(c)) cin.unget();
  return is >> x.num >> c >> x.den;
}

ostream& operator<<(ostream& os, const Fraction& x) {
  os << (x.sign == -1 ? "-" : "") << x.num;
  if (x.den > 1) os << '/' << x.den;
  return os;
}

Fraction operator+(const Fraction& x, const Fraction& y) {
  Fraction z = 0;
  z.den = lcm(x.den, y.den);
  z.num = x.sign * z.den / x.den * x.num + y.sign * z.den / y.den * y.num;
  return z.Simplify();
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Fraction x = 0;
  vector<Fraction> a;
  while (cin >> x) a.push_back(x);
  for (auto& x : a) cout << x << endl;
  Fraction sum = 0;
  for (auto& x : a) sum = sum + x;
  cout << sum << endl;
  return 0;
}
