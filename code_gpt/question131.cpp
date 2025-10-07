/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string colar;
    cin >> N >> colar;
    
    int maxPedras = 0;
    
    for (int i = 0; i < N; i++) {
        char corAtual = colar[i];
        int cont = 0;
        
        // Contando para a esquerda
        for (int j = i; j >= 0 && (colar[j] == corAtual || colar[j] == 'w'); j--) {
            cont++;
        }
        // Contando para a direita
        for (int j = i + 1; j < N + N; j++) {
            if (colar[j % N] == corAtual || colar[j % N] == 'w') {
                cont++;
            } else {
                break;
            }
        }
        
        maxPedras = max(maxPedras, cont);
    }
    
    cout << maxPedras << endl;
    return 0;
}
