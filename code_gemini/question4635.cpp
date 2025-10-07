/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int c;
    string s;
    cin >> c >> s;

    for (char& ch : s) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = toupper(base + (toupper(ch) - base + c % 26 + 26) % 26);
        }
    }

    cout << s << endl;

    return 0;
}
