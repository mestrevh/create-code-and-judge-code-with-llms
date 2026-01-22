/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

vector<string> nomes;
int64_t X, K;

int64_t produzir(int idx) {
    if (idx >= nomes.size()) return 0;
    int64_t dinheiro_subordinado1 = produzir(2 * idx + 1);
    int64_t dinheiro_subordinado2 = produzir(2 * idx + 2);

    int64_t produzido = (idx >= nomes.size()) ? X : dinheiro_subordinado1 + dinheiro_subordinado2;
    
    cout << "Estou dando " << produzido << " euros a " << (idx == 0 ? "Nairobi" : nomes[idx / 2]) << endl;
    
    return produzido;
}

int main() {
    int N;
    cin >> N;

    nomes.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> nomes[i];
    }

    cin >> X >> K;

    int64_t total_produzido = produzir(0);

    if (total_produzido >= K) {
        cout << "Bom trabalho" << endl;
    } else {
        cout << "Precisamos acelerar o processo" << endl;
    }

    return 0;
}
