/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Contas acima de 100 reais: 0" << std::endl;
        std::cout << "Contas sem dividas: 0" << std::endl;
        std::cout << "Soma das dividas: R$ 0.00" << std::endl;
        return 0;
    }

    std::vector<std::string> nomes(n);
    std::vector<double> saldos(n, 0.0);

    for (int i = 0; i < n; ++i) {
        std::cin >> nomes[i];
    }

    std::string nome_operacao;
    while (std::cin >> nome_operacao && nome_operacao != "FIM") {
        char tipo_operacao;
        double valor_operacao;
        std::cin >> tipo_operacao >> valor_operacao;

        for (int i = 0; i < n; ++i) {
            if (nomes[i] == nome_operacao) {
                if (tipo_operacao == 'C') {
                    saldos[i] += valor_operacao;
                } else if (tipo_operacao == 'P') {
                    saldos[i] -= valor_operacao;
                }
                break;
            }
        }
    }

    int contas_acima_100 = 0;
    int contas_sem_divida = 0;
    double soma_dividas = 0.0;
    double maior_divida = -1.0;
    int indice_maior_devedor = 0;

    for (int i = 0; i < n; ++i) {
        if (saldos[i] > 100.0) {
            contas_acima_100++;
        }
        if (saldos[i] == 0.0) {
            contas_sem_divida++;
        }
        soma_dividas += saldos[i];

        if (saldos[i] > maior_divida) {
            maior_divida = saldos[i];
            indice_maior_devedor = i;
        }
    }
    
    if (maior_divida < 0) {
        maior_divida = 0;
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Contas acima de 100 reais: " << contas_acima_100 << std::endl;
    std::cout << "Contas sem dividas: " << contas_sem_divida << std::endl;
    std::cout << "Soma das dividas: R$ " << soma_dividas << std::endl;
    std::cout << "Maior divida: " << nomes[indice_maior_devedor] << " - R$ " << maior_divida << std::endl;

    return 0;
}
