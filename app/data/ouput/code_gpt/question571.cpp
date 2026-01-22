/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int qtd_refeicoes;
    cin >> qtd_refeicoes;

    int troco_total = 0;
    for (int i = 0; i < qtd_refeicoes; i++) {
        int valor;
        cin >> valor;
        troco_total += valor - 325;
    }
    
    int refeicoes_devidas = troco_total / 325;
    cout << refeicoes_devidas << endl;

    return 0;
}
