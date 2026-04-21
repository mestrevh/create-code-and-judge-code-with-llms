/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ataque, defesa;
    if (!getline(cin, ataque)) return 0;
    if (!getline(cin, defesa)) return 0;

    auto toLower = [](string s) {
        for (char &c : s) c = (char)tolower((unsigned char)c);
        return s;
    };

    ataque = toLower(ataque);
    defesa = toLower(defesa);

    if (ataque == defesa) {
        cout << "Empate\n";
        return 0;
    }

    map<string, int> idx = {
        {"fogo", 0}, {"agua", 1}, {"planta", 2}
    };

    vector<string> types = {"fogo", "agua", "planta"};
    int a = idx[ataque];
    int d = idx[defesa];

    int result = (a - d + 3) % 3;
    if (result == 2) cout << "Vantagem\n";
    else cout << "Desvantagem\n";

    return 0;
}