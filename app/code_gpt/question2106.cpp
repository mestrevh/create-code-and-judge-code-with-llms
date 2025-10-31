/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tabuleiro(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> tabuleiro[i];
    }
    
    int melhor_posicao = 0```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tabuleiro(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> tabuleiro[i];
    }

    int melhor_posicao = 0, max_pulos = 0;

    for (int inicio = 0; inicio < n; ++inicio) {
        int total_pulos = 0;
        int posicao = inicio;

        for (int pulo = 0; pulo < k; ++pulo) {
            total_pulos += tabuleiro[posicao];
            posicao = (posicao + tabuleiro[posicao]) % n;
        }

        if (total_pulos > max_pulos) {
            max_pulos = total_pulos;
            melhor_posicao = inicio;
        }
    }

    cout << melhor_posicao << " " << max_pulos << endl;
    return 0;
}
