/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool startsWithSame(const string& a, const string& b) {
    return a == b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lista;
    string nome;
    while (cin >> nome) {
        if (nome == "FIM") break;
        lista.push_back(nome);
    }

    sort(lista.begin(), lista.end());

    auto imprimir = [&](const vector<string>& v) {
        for (const auto& s : v) cout << s << "\n";
        for (int i = 0; i < 50; i++) cout << '-';
        cout << "\n";
    };

    imprimir(lista);

    int n;
    bool firstGroup = true;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> grupo;
        grupo.reserve(n);
        for (int i = 0; i < n; i++) {
            cin >> nome;
            grupo.push_back(nome);
        }

        if (!grupo.empty()) {
            vector<string> merged;
            merged.reserve(lista.size() + grupo.size());

            size_t i = 0, j = 0;
            while (i < lista.size() && j < grupo.size()) {
                if (lista[i] <= grupo[j]) {
                    merged.push_back(lista[i++]);
                } else {
                    merged.push_back(grupo[j++]);
                }
            }
            while (i < lista.size()) merged.push_back(lista[i++]);
            while (j < grupo.size()) merged.push_back(grupo[j++]);

            lista.swap(merged);
        }

        imprimir(lista);
    }

    return 0;
}