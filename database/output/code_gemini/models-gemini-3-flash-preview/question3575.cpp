/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    bool found = false;
    while (cin >> s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = (char)(c + 32);
            }
        }
        if (s.find("zelda") != string::npos) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Link Bolado" << "\n";
    } else {
        cout << "Link Tranquilo" << "\n";
    }

    return 0;
}