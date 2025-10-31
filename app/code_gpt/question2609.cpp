/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lista;

    for (int i = 0; i < N; i++) {
        int valor;
        cin >> valor;
        lista.push_back(valor);
    }

    int pos, novo_valor;
    cin >> pos >> novo_valor;

    cout << "[ ";
    for (int i = 0; i < lista.size(); i++) {
        cout << lista[i] << (i < lista.size() - 1 ? " " : " ");
    }
    cout << "]" << endl;

    if (pos < 0 || pos > lista.size()) {
        cout << "A posicao " << pos << " estah fora do intervalo" << endl;
    } else {
        lista.insert(lista.begin() + pos, novo_valor);
        cout << "[ ";
        for (int i = 0; i < lista.size(); i++) {
            cout << lista[i] << (i < lista.size() - 1 ? " " : " ");
        }
        cout << "]" << endl;
    }

    return 0;
}
