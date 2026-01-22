/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> precos(N);

    for (int i = 0; i < N; i++) {
        int D;
        double P;
        cin >> D >> P;

        double desconto;
        switch (D) {
            case 0: desconto = 0.25; break;
            case 1: desconto = 0.20; break;
            case 2: desconto = 0.18; break;
            case 3: desconto = 0.15; break;
            case 4: desconto = 0.12; break;
            case 5: desconto = 0.10; break;
        }

        double novo_preco = P * (1 - desconto);
        if (P <= 100.0) {
            novo_preco = P * (1 - desconto / 2);
        }
        if (novo_preco < 45.0) novo_preco = 45.0;

        precos[i] = novo_preco;
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < N; i++) {
        cout << "Jogo[" << i << "] = R$" << precos[i] << endl;
    }

    return 0;
}
