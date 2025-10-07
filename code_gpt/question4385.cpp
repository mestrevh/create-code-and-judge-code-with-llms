/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, capacidade;
    
    while (cin >> N >> capacidade) {
        int viagens = (N + capacidade - 1) / capacidade;
        for (int i = 0; i < viagens; i++) {
            if (i < viagens - 1 || N % capacidade == 0) {
                cout << capacidade << endl;
            } else {
                cout << N % capacidade << endl;
            }
        }
    }
    
    return 0;
}
