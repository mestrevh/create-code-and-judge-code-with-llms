/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<char, int> categorias;
    int totalGeral = 0;

    for (int i = 0; i < N; ++i) {
        char categoria;
        int valor;
        cin >> categoria >> valor;
        categorias[categoria] += valor;
        totalGeral += valor;
    }

    for (const auto& par : categorias) {
        cout << par.first << " " << par.second << endl;
    }
    cout << "TOTAL " << totalGeral << endl;

    return 0;
}
