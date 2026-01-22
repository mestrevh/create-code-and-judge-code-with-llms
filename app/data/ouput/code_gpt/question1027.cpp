/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string nomes[n];
    double saldos[n] = {0};

    for (int i = 0; i < n; ++i) {
        cin >> nomes[i];
    }

    string operacao, nome;
    double valor;
    
    while (true) {
        cin >> nome;
        if (nome == "FIM") break;
        cin >> operacao >> valor;

        for (int i = 0; i < n; ++i) {
            if (nomes[i] == nome) {
                if (operacao == "C") {
                    saldos[i] += valor;
                } else if (operacao == "P") {
                    saldos[i] -= valor;
                }
                break;
            }
        }
    }

    int acima_de_100 = 0, sem_dividas = 0;
    double soma_dividas = 0, maior_divida = 0;
    string maior_devedor;

    for (int i = 0; i < n; ++i) {
        if (saldos[i] > 100) acima_de_100++;
        if (saldos[i] == 0) sem_dividas++;
        if (saldos[i] > maior_divida) {
            maior_divida = saldos[i];
            maior_devedor = nomes[i];
        }
        soma_dividas += saldos[i];
    }

    cout << "Contas acima de 100 reais: " << acima_de_100 << endl;
    cout << "Contas sem dividas: " << sem_dividas << endl;
    cout << fixed << setprecision(2);
    cout << "Soma das dividas: R$ " << soma_dividas << endl;
    cout << "Maior divida: " << maior_devedor << " - R$ " << maior_divida << endl;

    return 0;
}
