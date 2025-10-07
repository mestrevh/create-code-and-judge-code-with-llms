/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int P, E;
    cin >> P >> E;
    int votos[E][P];
    
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < P; j++) {
            cin >> votos[i][j];
        }
    }

    for (int j = 0; j < P; j++) {
        int totalVotos = 0;
        for (int i = 0; i < E; i++) {
            totalVotos += votos[i][j];
        }
        cout << "Princesa " << j + 1 << ": " << totalVotos << " voto(s)" << endl;
    }

    return 0;
}
