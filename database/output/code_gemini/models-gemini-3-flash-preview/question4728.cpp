/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) {
        return 0;
    }

    stack<char> s;
    for (char c : line) {
        if (c == ' ') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << ' ';
        } else {
            s.push(c);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

    return 0;
}