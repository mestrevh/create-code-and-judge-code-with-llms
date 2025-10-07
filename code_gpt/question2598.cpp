/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, value;
    cin >> n;
    vector<int> lista;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lista.push_back(num);
    }

    cin >> value;

    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << lista[i] << (i < n - 1 ? " " : " ");
    }
    cout << "]" << endl;

    if (n == 0) {
        cout << "A lista estah vazia - nao eh possivel remover elemento" << endl;
        return 0;
    }

    bool found = false;
    vector<int> novaLista;
    
    for (int i = 0; i < n; i++) {
        if (lista[i] == value && !found) {
            found = true;
            continue;
        }
        novaLista.push_back(lista[i]);
    }

    if (!found) {
        cout << "Nao eh possivel remover o elemento " << value << endl;
    } else {
        cout << "[ ";
        for (int i = 0; i < novaLista.size(); i++) {
            cout << novaLista[i] << (i < novaLista.size() - 1 ? " " : " ");
        }
        cout << "]" << endl;
    }

    return 0;
}
