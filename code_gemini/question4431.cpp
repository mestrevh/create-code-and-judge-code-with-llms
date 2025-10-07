/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    while (true) {
        size_t pos = s.find("abc");
        if (pos == string::npos) {
            break;
        }
        s.erase(pos, 3);
    }

    if (s.empty()) {
        cout << "string vazia" << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}
