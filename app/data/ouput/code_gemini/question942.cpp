/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int dias_mes;
    std::cin >> dias_mes;

    std::vector<double> vendas(dias_mes);

    for (int i = 0; i < dias_mes; ++i) {
        std::cin >> vendas[i];
    }

    int dias_funcionou = 0;
    for (int i = 0; i < dias_mes; ++i) {
        if (vendas[i] > 0) {
            dias_funcionou++;
        }
    }

    double total_vendas = 0.0;
    for (int i = 0; i < dias_mes; ++i) {
        total_vendas += vendas[i];
    }

    double maior_faturamento = 0.0;
    for (int i = 0; i < dias_mes; ++i) {
        if (vendas[i] > maior_faturamento) {
            maior_faturamento = vendas[i];
        }
    }

    double menor_faturamento = 0.0;
    if (dias_funcionou > 0) {
        menor_faturamento = std::numeric_limits<double>::max();
        for (int i = 0; i < dias_mes; ++i) {
            if (vendas[i] > 0 && vendas[i] < menor_faturamento) {
                menor_faturamento = vendas[i];
            }
        }
    }

    std::vector<int> dias_maior;
    for (int i = 0; i < dias_mes; ++i) {
        if (vendas[i] == maior_faturamento) {
            dias_maior.push_back(i + 1);
        }
    }

    std::vector<int> dias_menor;
    if (dias_funcionou > 0) {
        for (int i = 0; i < dias_mes; ++i) {
            if (vendas[i] == menor_faturamento) {
                dias_menor.push_back(i + 1);
            }
        }
    }

    double media_mes = (dias_mes > 0) ? total_vendas / dias_mes : 0.0;
    double media_funcionamento = (dias_funcionou > 0) ? total_vendas / dias_funcionou : 0.0;

    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << dias_funcionou << std::endl;
    std::cout << media_mes << std::endl;
    std::cout << media_funcionamento << std::endl;
    std::cout << maior_faturamento << std::endl;
    
    bool first = true;
    for (int dia : dias_maior) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << dia;
        first = false;
    }
    std::cout << std::endl;

    std::cout << menor_faturamento << std::endl;
    
    first = true;
    if (dias_funcionou > 0) {
        for (int dia : dias_menor) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << dia;
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
