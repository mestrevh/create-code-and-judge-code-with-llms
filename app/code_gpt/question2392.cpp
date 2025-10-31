/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> lado1(N), lado2(N);
    for (int i = 0; i < N; i++) cin >> lado1[i];
    for (int i = 0; i < N; i++) cin >> lado2[i];

    int min_chuva = N; // valor maximo de chuva possível

    // calcular chuva sem cruzar
    int chuva1 = 0, chuva2 = 0;
    for (int i = 0; i < N; i++) {
        chuva1 += (lado1[i] == 0);
        chuva2 += (lado2[i] == 0);
    }
    min_chuva = min(min_chuva, min(chuva1, chuva2));

    // calcular com cruzamento
    int chuva_lado1 = 0, chuva_lado2 = 0;
    for (int i = 0; i < N; i++) {
        chuva_lado1 += (lado1[i] == 0);
        min_chuva = min(min_chuva, chuva_lado1 + (N - i - 1 - count(lado2.begin() + i + 1, lado2.end(), 1)));
    }

    chuva_lado2 = 0;
    for (int i = 0; i < N; i++) {
        chuva_lado2 += (lado2[i] == 0);
        min_chuva = min(min_chuva, chuva_lado2 + (N - i - 1 - count(lado1.begin() + i + 1, lado1.end(), 1)));
    }

    cout << min_chuva << endl;
    return 0;
}
