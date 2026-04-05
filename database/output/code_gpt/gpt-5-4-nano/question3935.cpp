/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N)) return 0;

    vector<string> carro(N);
    for (int i = 0; i < N; i++) cin >> carro[i];

    cin >> M;
    vector<string> moto(M);
    for (int i = 0; i < M; i++) cin >> moto[i];

    int n1, n2;
    cin >> n1 >> n2;

    sort(carro.begin(), carro.end());
    sort(moto.begin(), moto.end());

    string vencedor_carro = carro[n1 - 1];
    string vencedor_moto = moto[n2 - 1];

    if (vencedor_carro == vencedor_moto) {
        cout << "Quem ganhou tudo hoje foi " << vencedor_carro;
    } else {
        cout << "Quem ganhou o carro foi: " << vencedor_carro << "\n";
        cout << "Quem ganhou a moto foi: " << vencedor_moto;
    }
    return 0;
}