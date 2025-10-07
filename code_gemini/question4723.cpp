/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> compras = {"leite", "manteiga", "ovos"};
    string adicionar, remover;
    cin >> adicionar >> remover;

    compras.push_back(adicionar);

    for (int i = 0; i < compras.size(); ++i) {
        if (compras[i] == remover) {
            compras.erase(compras.begin() + i);
            break;
        }
    }

    cout << "[";
    for (int i = 0; i < compras.size(); ++i) {
        cout << "'" << compras[i] << "'";
        if (i < compras.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
