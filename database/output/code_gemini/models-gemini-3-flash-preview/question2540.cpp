/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int pos;
    cin >> pos;

    // Apresentar a lista criada
    cout << "[ ";
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;

    if (n == 0) {
        cout << "A lista estah vazia - nao eh possivel remover elementos" << endl;
    } else if (pos < 0 || pos >= n) {
        cout << "Nao eh possivel remover o elemento" << endl;
    } else {
        int itemRemovido = v[pos];
        
        // Criar a nova lista sem o elemento (simulando restrições de append/len)
        vector<int> novaLista;
        if (n > 1) novaLista.reserve(n - 1);
        
        for (int i = 0; i < n; ++i) {
            if (i != pos) {
                novaLista.push_back(v[i]);
            }
        }

        // Apresentar item removido
        cout << "O item " << itemRemovido << " serah removido da lista" << endl;

        // Apresentar a lista sem o item
        cout << "[ ";
        for (int i = 0; i < (int)novaLista.size(); ++i) {
            cout << novaLista[i] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}