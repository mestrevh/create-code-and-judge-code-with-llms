/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numero_consumidor;
    int kwh_consumidos;
    int tipo_consumidor;

    long long total_consumo_acumulado = 0;
    long long soma_kwh_1_2 = 0;
    int contador_1_2 = 0;

    while (true) {
        std::cout << "Digite o numero do consumidor:" << std::endl;
        std::cin >> numero_consumidor;

        if (numero_consumidor == 0) {
            break;
        }

        std::cout << "Digite a quantidade de KWh consumidos:" << std::endl;
        std::cin >> kwh_consumidos;

        std::cout << "Digite o tipo de consumidor:" << std::endl;
        std::cin >> tipo_consumidor;

        double preco_kwh = 0.0;
        if (tipo_consumidor == 1) {
            preco_kwh = 0.3;
        } else if (tipo_consumidor == 2) {
            preco_kwh = 0.5;
        } else if (tipo_consumidor == 3) {
            preco_kwh = 0.7;
        }

        double custo_total = kwh_consumidos * preco_kwh;
        total_consumo_acumulado += kwh_consumidos;

        if (tipo_consumidor == 1 || tipo_consumidor == 2) {
            soma_kwh_1_2 += kwh_consumidos;
            contador_1_2++;
        }

        double media_1_2 = 0.0;
        if (contador_1_2 > 0) {
            media_1_2 = static_cast<double>(soma_kwh_1_2) / contador_1_2;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Custo total para o consumidor " << numero_consumidor << ": R$ " << custo_total << std::endl;
        
        std::cout << "Total de consumo acumulado: " << total_consumo_acumulado << " Kwh" << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Media de consumo dos tipos 1 e 2: " << media_1_2 << " KWh" << std::endl;
    }

    return 0;
}
