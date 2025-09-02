#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    string s = to_string(num);
    if (s[0] == '-') s = s.substr(1);
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (s == rev)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}