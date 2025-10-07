/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; ++i) {
        string line;
        getline(cin, line);
        cout << (isValid(line) ? 'S' : 'N') << endl;
    }
    return 0;
}
