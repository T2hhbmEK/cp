#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace hpint {
template <typename T>
inline int sz(T x) {
  return (int)x.size();
}
struct HPInt {  // High Precision Integer
  static constexpr int kBase = 10000;
  static constexpr int kMaxN = 1024;
  vector<int> a;

  HPInt(int x = 0) {
    while (x) a.push_back(x % kBase), x /= kBase;
  }
  HPInt(long long x) {
    while (x) a.push_back(x % kBase), x /= kBase;
  }
  HPInt(const string &s) {
    for (int i = 0, c = 0; i < sz(s); ++i) {
      c = c * 10 + (s[i] & 0xF);
      if ((sz(s) - 1 - i) % kBase == 0) a.push_back(c), c = 0;
    }
    reverse(a.begin(), a.end());
    flatten();
  }

  HPInt &strip() {
    while (!a.empty() && a.back() == 0) a.pop_back();
    return *this;
  }
  HPInt &flatten(bool __strip = true) {
    for (int i = 0; i + 1 < sz(a); ++i) {
      a[i + 1] += a[i] / kBase;
      a[i] %= kBase;
    }
    if (__strip) this->strip();
    return *this;
  }

  friend int Compare(const HPInt &x, const HPInt &y) {
    if (sz(x.a) != sz(y.a)) return sz(x.a) - sz(y.a);
    for (int i = sz(x.a) - 1; i >= 0; --i) {
      if (x.a[i] != y.a[i]) return x.a[i] - y.a[i];
    }
    return 0;
  }

#define HPINT_DEF_CMP(op)                                   \
  friend bool operator op(const HPInt &x, const HPInt &y) { \
    return Compare(x, y) op 0;                              \
  }
  HPINT_DEF_CMP(==) HPINT_DEF_CMP(<) HPINT_DEF_CMP(>);
  HPINT_DEF_CMP(!=) HPINT_DEF_CMP(<=) HPINT_DEF_CMP(>=);

  friend ostream &operator<<(ostream &os, const HPInt &x) {
    if (x.a.empty()) return os << 0;
    os << x.a.back();
    for (int i = sz(x.a) - 2, w = log10(kBase); i >= 0; --i) {
      os << setfill('0') << setw(w) << x.a[i];
    }
    return os;
  }
  inline string to_string() {
    ostringstream oss;
    oss << *this;
    return oss.str();
  }
  friend istream &operator>>(istream &is, HPInt &x) {
    string s;
    is >> s;
    x = s;
    return is;
  }

  friend HPInt &operator+=(HPInt &x, const HPInt &y) {
    x.a.resize(max(sz(x.a), sz(y.a)) + 1, 0);
    for (int i = 0; i < sz(y.a); ++i) x.a[i] += y.a[i];
    return x.flatten();
  }
  friend HPInt operator+(const HPInt &x, const HPInt &y) {
    HPInt z = x;
    return z += y;
  }
  friend HPInt &operator-=(HPInt &x, const HPInt &y) {
    assert(x >= y);
    for (int i = 0; i < sz(y.a); ++i) {
      while (x.a[i] < y.a[i]) x.a[i] += kBase, x.a[i + 1] -= 1;
      x.a[i] -= y.a[i];
    }
    return x.flatten();
  }
  friend HPInt operator-(const HPInt &x, const HPInt &y) {
    HPInt z = x;
    return z -= y;
  }
  friend HPInt &operator*=(HPInt &x, const HPInt &y) {
    HPInt z = x * y;
    return x = z;
  }
  friend HPInt operator*(const HPInt &x, const HPInt &y) {
    HPInt z;
    z.a.resize(sz(x.a) + sz(y.a), 0);
    for (int i = 0; i < sz(x.a); ++i) {
      for (int j = 0; j < sz(y.a); ++j) {
        z.a[i + j] += x.a[i] * y.a[j];
      }
      z.flatten(false);
    }
    return z.flatten();
  }
  friend HPInt &operator/=(HPInt &x, const int &y) {
    for (int i = sz(x.a) - 1; i >= 0; --i) {
      if (i > 0) x.a[i - 1] += x.a[i] % y * kBase;
      x.a[i] /= y;
    }
    return x.flatten();
  }
  friend HPInt operator/(const HPInt &x, const int &y) {
    HPInt z = x;
    return z /= y;
  }
};

}  // namespace hpint
