/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

float vantagem(float candidato[], float concorrente[], int n) {
    float max_vantagem = 0.0;
    for (int i = 0; i < n; i++) {
        if (candidato[i] > concorrente[i]) {
            float diff = candidato[i] - concorrente[i];
            if (diff > max_vantagem) {
                max_vantagem = diff;
            }
        }
    }
    return max_vantagem;
}

int main() {
    int n;
    cin >> n;
    float candidato[n], concorrente[n];
    for (int i = 0; i < n; i++) {
        cin >> candidato[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> concorrente[i];
    }
    float resultado = vantagem(candidato, concorrente, n);
    cout << fixed << setprecision(2) << resultado << endl;
    return 0;
}
