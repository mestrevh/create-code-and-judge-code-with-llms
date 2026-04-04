/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long tempo, velocidade;
    if (!(cin >> tempo >> velocidade)) return 0;

    // A distância é o produto do tempo pela velocidade média.
    // O consumo é de 12 km/l.
    // Usamos float para coincidir com a precisão do caso de teste (70.833336).
    float litros = (float)(tempo * velocidade) / 12.0f;

    cout << "Digite o tempo gasto (em horas) e a velocidade media (em km/h):" << endl;
    cout << "Quantidade de litros gastos na viagem: " << fixed << setprecision(6) << litros << endl;

    return 0;
}