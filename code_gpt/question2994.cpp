/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int R, N, soma = 0;
    cin >> R >> N;
    
    for (int i = 1; i <= N; i += R) {
        soma += i;
    }
    
    cout << "A somatoria da PA eh: " << soma << endl;
    return 0;
}
