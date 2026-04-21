/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cifra;
    if (!(cin >> cifra)) return 0;

    string dummy;
    getline(cin, dummy);

    string s;
    if (!getline(cin, s)) return 0;

    int shift = (cifra % 26 + 26) % 26;

    for (int i = 0; i < (int)s.length(); i++) {
        unsigned char ch = (unsigned char)s[i];
        if (isalpha(ch)) {
            int pos = toupper(ch) - 'A';
            int new_pos = (pos + shift) % 26;
            s[i] = (char)('A' + new_pos);
        }
    }

    cout << s << endl;

    return 0;
}