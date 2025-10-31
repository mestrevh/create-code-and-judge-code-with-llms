/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> notas(n);
    double soma = 0.0;
    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
        soma += notas[i];
    }

    double media = soma / n;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Media: " << media << std::endl;

    std::sort(notas.begin(), notas.end());
    double mediana;
    if (n % 2 != 0) {
        mediana = static_cast<double>(notas[n / 2]);
    } else {
        mediana = (static_cast<double>(notas[n / 2 - 1] + notas[n / 2])) / 2.0;
    }
    std::cout << "Mediana: " << mediana << std::endl;

    int freq[11] = {0};
    for (int nota : notas) {
        freq[nota]++;
    }

    int max_freq = 0;
    for (int i = 0; i <= 10; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    int moda = -1;
    int count_max_freq = 0;
    for (int i = 0; i <= 10; ++i) {
        if (freq[i] == max_freq) {
            count_max_freq++;
            moda = i;
        }
    }

    if (count_max_freq == 1) {
        std::cout << "Moda: " << static_cast<double>(moda) << std::endl;
    } else {
        std::cout << "Nao tem moda" << std::endl;
    }

    return 0;
}
