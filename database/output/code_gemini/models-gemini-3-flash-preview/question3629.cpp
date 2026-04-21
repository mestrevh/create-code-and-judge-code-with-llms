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

    string s;
    int k;

    while (cin >> s >> k) {
        for (char c : s) {
            unsigned char uc = static_cast<unsigned char>(c);
            if (isalpha(uc)) {
                int n = tolower(uc) - 'a';
                int shifted = (n + (k % 26) + 26) % 26;
                cout << static_cast<char>(shifted + 'a');
            } else {
                cout << static_cast<char>(tolower(uc));
            }
        }
        cout << '\n';
    }

    return 0;
}