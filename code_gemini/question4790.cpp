/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    list<char> text;
    auto it = text.begin();

    for (char c : s) {
        if (c == '[') {
            it = text.begin();
        } else if (c == ']') {
            it = text.end();
        } else {
            text.insert(it, c);
        }
    }

    for (char c : text) {
        cout << c;
    }
    cout << endl;

    return 0;
}
