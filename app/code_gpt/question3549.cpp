/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    
    int total = A + B;
    double desconto = (C == 0) ? 0.05 : 0.15;
    double precoTotal = D * E * (1 - desconto);
    
    if (precoTotal <= total) {
        cout << "Faz um Ifood!" << endl;
    } else {
        cout << "pede menos que as esfihas nao vao acabar hoje!" << endl;
    }
    
    return 0;
}
