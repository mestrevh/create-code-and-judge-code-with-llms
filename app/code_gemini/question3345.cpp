/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a;
    std::cin >> n >> a;

    std::vector<int> max_values(n, INT_MIN);
    std::vector<int> min_values(n, INT_MAX);

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < n; ++j) {
            int reading;
            std::cin >> reading;
            if (reading > max_values[j]) {
                max_values[j] = reading;
            }
            if (reading < min_values[j]) {
                min_values[j] = reading;
            }
        }
    }

    std::vector<int> current_readings(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> current_readings[i];
    }

    std::vector<int> processed_values(n);
    for (int i = 0; i < n; ++i) {
        long long valor_lido = current_readings[i];
        long long entrada_min = min_values[i];
        long long entrada_max = max_values[i];
        long long saida;

        if (entrada_max == entrada_min) {
            saida = (valor_lido <= entrada_min) ? 0 : 1000;
        } else {
            saida = ((valor_lido - entrada_min) * 1000) / (entrada_max - entrada_min);
        }
        
        if (saida < 0) {
            saida = 0;
        }
        if (saida > 1000) {
            saida = 1000;
        }
        
        processed_values[i] = 1000 - saida;
    }

    long long numerator = 0;
    long long denominator = 0;
    for (int i = 0; i < n; ++i) {
        numerator += (long long)processed_values[i] * i * 1000;
        denominator += processed_values[i];
    }
    
    long long posicao;
    if (denominator == 0) {
        posicao = (long long)(n - 1) * 500;
    } else {
        posicao = numerator / denominator;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << max_values[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << min_values[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
    
    for (int i = 0; i < n; ++i) {
        std::cout << processed_values[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
    
    std::cout << posicao << "\n";

    return 0;
}
