/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int encontrarMaiorNumero(const vector<int>& celulares, int inicio, int fim) {
    if (inicio == fim) {
        return celulares[inicio];
    }
    int meio = (inicio + fim) / 2;
    int maiorEsquerda = encontrarMaiorNumero(celulares, inicio, meio);
    int maiorDireita = encontrarMaiorNumero(celulares, meio + 1, fim);
    return max(maiorEsquerda, maiorDireita);
}

int main() {
    int N;
    cin >> N;
    vector<string> nomes(N);
    vector<int> celulares(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> nomes[i] >> celulares[i];
    }
    
    int maiorNumero = encontrarMaiorNumero(celulares, 0, N - 1);
    int alisonNumero = 95567546;
    
    if (maiorNumero == alisonNumero) {
        cout << "Ela nao tentou bancar a espertinha de novo!" << endl;
    } else {
        cout << "ELA ROUBOU DE NOVO! TODOS ATRAS DE ALISON! O maior numero na parede e " << maiorNumero << "!" << endl;
    }
    
    return 0;
}
