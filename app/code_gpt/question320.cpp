/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, G;
    cin >> N >> G;
    
    int pontos = 0;
    vector<int> resultados(N);
    
    for (int i = 0; i < N; i++) {
        int S, R;
        cin >> S >> R;
        if (S > R) pontos += 3;
        else if (S == R) pontos += 1;
        resultados[i] = S - R;
    }
    
    sort(resultados.rbegin(), resultados.rend());
    for (int i = 0; i < G && i < N; i++) {
        if (resultados[i] < 0) {
            pontos += 3; // uma derrota se torna uma vitória
        } else if (resultados[i] == 0) {
            pontos += 1; // um empate se torna uma vitória
        }
    }

    cout << pontos << endl;

    return 0;
}
