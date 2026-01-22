/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int C, D;
    cin >> C >> D;
    
    string vencedor;
    int tempo_minimo = numeric_limits<int>::max();
    
    for (int i = 0; i < C; ++i) {
        string nome;
        int TL, DO, TO;
        cin >> nome >> TL >> DO >> TO;

        int num_obstaculos = D / DO;
        int tempo_total = (TL * 60) + (num_obstaculos * TO);

        if (tempo_total < tempo_minimo) {
            tempo_minimo = tempo_total;
            vencedor = nome;
        }
    }
    
    cout << vencedor << " venceu a corrida em " << tempo_minimo << " segundos!" << endl;
    return 0;
}
