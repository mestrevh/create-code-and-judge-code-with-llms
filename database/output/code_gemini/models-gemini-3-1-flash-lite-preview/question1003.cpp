/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Aposta {
    string codigo;
    int acertos;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sorteados(10);
    for (int i = 0; i < 10; ++i) {
        cin >> sorteados[i];
    }
    sort(sorteados.begin(), sorteados.end());

    int N;
    cin >> N;

    vector<Aposta> apostas(N);
    int min_acertos = 16, max_acertos = -1;

    for (int i = 0; i < N; ++i) {
        cin >> apostas[i].codigo;
        int count = 0;
        for (int j = 0; j < 15; ++j) {
            int num;
            cin >> num;
            if (binary_search(sorteados.begin(), sorteados.end(), num)) {
                count++;
            }
        }
        apostas[i].acertos = count;
        if (count < min_acertos) min_acertos = count;
        if (count > max_acertos) max_acertos = count;
    }

    vector<string> vencedores_max, vencedores_min;
    for (const auto& a : apostas) {
        if (a.acertos == max_acertos) vencedores_max.push_back(a.codigo);
        if (a.acertos == min_acertos) vencedores_min.push_back(a.codigo);
    }

    cout << "Faixa: " << max_acertos << " acertos" << endl;
    for (const auto& c : vencedores_max) cout << c << endl;
    cout << vencedores_max.size() << " ganhadores" << endl << endl;

    cout << "Faixa: " << min_acertos << " acerto" << (min_acertos == 1 ? "" : "s") << endl;
    for (const auto& c : vencedores_min) cout << c << endl;
    cout << vencedores_min.size() << " ganhador" << (vencedores_min.size() == 1 ? "" : "es") << endl;

    return 0;
}