/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool canReduceToEmpty(string s) {
    stack<char> stk;
    for (char c : s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.empty();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << (canReduceToEmpty(s) ? 1 : 0) << endl;
    }
    return 0;
}
