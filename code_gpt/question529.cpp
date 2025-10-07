/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int Q, P;
        cin >> Q >> P;

        vector<stack<int>> pilhas(P);
        queue<int> lavar;
        
        for (int i = 0; i < P; ++i) {
            int tamanho;
            cin >> tamanho;
            for (int j = 0; j < tamanho; ++j) {
                int camisa;
                cin >> camisa;
                pilhas[i].push(camisa);
            }
        }

        while (Q--) {
            int pedido;
            cin >> pedido;

            if (pedido == 1) {
                int festa;
                cin >> festa;
                bool sucesso = false;

                for (int i = 0; i < P; ++i) {
                    if (!pilhas[i].empty()) {
                        int camisa = pilhas[i].top();
                        if (festa - 1 <= camisa && camisa <= festa + 1) {
                            cout << camisa << endl;
                            pilhas[i].pop();
                            lavar.push(camisa);
                            sucesso = true;
                            break;
                        }
                    }
                }

                if (!sucesso) {
                    cout << "ze nao vai pra festa " << festa << endl;
                }
            } else if (pedido == 2) {
                if (lavar.empty()) {
                    cout << "nao tem roupa pra lavar" << endl;
                } else {
                    cout << lavar.front() << endl;
                    lavar.pop();
                }
            }
        }
    }
    return 0;
}
