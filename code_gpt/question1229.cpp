/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<stack<int>> pilhas;
    
    while (n--) {
        string comando;
        cin >> comando;

        if (comando[0] == 'c') {
            int k;
            cin >> k;
            pilhas.resize(k);
        } else if (comando[0] == 'i') {
            int valor;
            cin >> valor;
            for (int i = 0; i < pilhas.size(); i++) {
                if (pilhas[i].size() < 1 + i) {
                    pilhas[i].push(valor);
                    break;
                }
            }
        } else if (comando[0] == 'r') {
            for (int i = pilhas.size() - 1; i >= 0; i--) {
                if (!pilhas[i].empty()) {
                    pilhas[i].pop();
                    break;
                }
            }
        }

        cout << "Conjunto de pilhas:\n";
        bool vazio = true;
        for (int i = 0; i < pilhas.size(); i++) {
            cout << "pilha:\n";
            if (!pilhas[i].empty()) {
                vazio = false;
                stack<int> temp = pilhas[i];
                vector<int> elementos;
                while (!temp.empty()) {
                    elementos.push_back(temp.top());
                    temp.pop();
                }
                for (int j = elementos.size() - 1; j >= 0; j--) {
                    cout << elementos[j] << " ";
                }
                cout << endl;
            }
        }
        if (vazio) {
            cout << "conjunto de pilhas vazio!\n";
        }
    }
    
    return 0;
}
