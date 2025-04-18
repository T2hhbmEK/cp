#include <bits/stdc++.h>
using namespace std;
int main() {
	ostringstream oss;
    oss << acos(-1);
	string s = oss.str();
	cout << s << endl;
    cout << atof(s.c_str()) << endl;
    cout << atoi(s.c_str()) << endl;
    cout << atoll(s.c_str()) << endl;
    cout << stoi(s) << endl;
    return 0;
}
