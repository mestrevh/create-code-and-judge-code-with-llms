/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

string remover_especiais(string palavra) {
    string resultado = "";
    for (char c : palavra) {
        if (c == '.' || c == '"' || c == '(' || c == '*' || c == '$' || c == '#' || c == ':') {
            continue;
        }
        resultado += c;
    }
    return resultado;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> dicionario;
    string token;

    while (cin >> token) {
        if (token == "-1") {
            break;
        }

        string palavra_limpa = remover_especiais(token);
        
        if (!palavra_limpa.empty()) {
            for (int i = 0; i < (int)palavra_limpa.length(); ++i) {
                palavra_limpa[i] = (char)tolower((unsigned char)palavra_limpa[i]);
            }
            dicionario.insert(palavra_limpa);
        }
    }

    for (const string &palavra : dicionario) {
        cout << palavra << "\n";
    }

    return 0;
}