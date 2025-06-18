#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (auto& ch : s) ch = toupper(ch);
    cout << s;
    return 0;
}
