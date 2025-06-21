#include <bits/stdc++.h>
using namespace std;

struct Student {
  string name;
  int age;
  int noip_score;
  void Train() {
    age++;
    noip_score = min(600, noip_score / 5 * 6);
  }
};

istream& operator>>(istream& cin, Student& x) {
  return cin >> x.name >> x.age >> x.noip_score;
}
ostream& operator<<(ostream& cout, Student& x) {
  return cout << x.name << " " << x.age << " " << x.noip_score;
}

int main() {
  int n;
  cin >> n;
  vector<Student> a(n);
  for (auto& x : a) cin >> x;
  for (auto& x : a) x.Train();
  for (auto& x : a) cout << x << endl;
  return 0;
}
