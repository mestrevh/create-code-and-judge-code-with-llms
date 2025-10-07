/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Crianca {
    string nome;
    int pontuacao;
};

bool compararCriancas(const Crianca& a, const Crianca& b) {
    if (a.pontuacao != b.pontuacao) {
        return a.pontuacao > b.pontuacao;
    }
    return a.nome < b.nome;
}

int main() {
    int n;
    cin >> n;

    vector<Crianca> criancas(n);
    for (int i = 0; i < n; ++i) {
        int o, b, r, p;
        cin >> criancas[i].nome >> criancas[i].pontuacao >> o >> b >> r >> p;
        criancas[i].pontuacao += (o * 5) + (b * 3) - (r * 3) - (p * 5);
    }

    sort(criancas.begin(), criancas.end(), compararCriancas);

    for (int i = 0; i < n; ++i) {
        cout << criancas[i].nome << " " << criancas[i].pontuacao << endl;
    }

    return 0;
}
