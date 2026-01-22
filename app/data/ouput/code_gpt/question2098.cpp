/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    double T;
    cin >> N >> T;
    
    vector<int> casas(N);
    vector<double> tamanhos(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> casas[i];
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> tamanhos[i];
    }
    
    for (int i = 0; i < N; ++i) {
        if (tamanhos[i] == T) {
            cout << "Cinderela mora na casa " << casas[i] << "!" << endl;
            return 0;
        }
    }
    
    cout << "Nenhuma das jovens e a moca do baile." << endl;
    return 0;
}
