#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c: s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s1 = "()[]{}";
    string s2 = "(]";

    cout << boolalpha;
    cout << "s1: " << isValid(s1) << endl;
    cout << "s2: " << isValid(s2) << endl;
    return 0;
}
