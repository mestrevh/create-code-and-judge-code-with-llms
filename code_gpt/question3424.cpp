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
    vector<int> numeros(N);
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }
    
    int maior = numeros[0], posicao = 0;
    for (int i = 1; i < N; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            posicao = i;
        }
    }
    
    cout << "o maior numero eh " << maior << ", e foi lido na posicao " << posicao << endl;
    return 0;
}
