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
    if (!getline(cin, s)) {
        return 0;
    }

    if (s.length() < 7) {
        while (s.length() < 7) {
            s += ' ';
        }
    }

    bool bread_ok = (s[0] == '.' || s[0] == ':') && (s[0] == s[6]);
    
    bool meat_ok = (s[1] == 'b' || s[1] == 'f' || s[1] == 'p' || s[1] == ' ');
    
    bool extras_ok = true;
    for (int i = 2; i <= 4; ++i) {
        if (s[i] != 'A' && s[i] != 'T' && s[i] != 'C' && s[i] != 'R' && s[i] != ' ') {
            extras_ok = false;
        }
    }
    
    bool sauce_ok = (s[5] == 'P');

    if (bread_ok && meat_ok && extras_ok && sauce_ok) {
        cout << "Valido" << endl;
    } else {
        cout << "Invalido" << endl;
        if (!sauce_ok) {
            cout << "...Mas pelo menos ganhou um chute" << endl;
        }
    }

    return 0;
}