/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    std::vector<int> nums(n);
    double soma = 0.0;
    std::map<int, int> frequencias;

    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        soma += nums[i];
        frequencias[nums[i]]++;
    }

    // Média
    double media = soma / n;

    // Mediana
    std::sort(nums.begin(), nums.end());
    double mediana;
    if (n % 2 != 0) {
        mediana = static_cast<double>(nums[n / 2]);
    } else {
        mediana = (static_cast<double>(nums[n / 2 - 1]) + static_cast<double>(nums[n / 2])) / 2.0;
    }

    // Moda
    int moda = 0;
    int max_freq = 0;
    for (auto const& par : frequencias) {
        if (par.second >= max_freq) {
            max_freq = par.second;
            moda = par.first;
        }
    }

    // Saída
    std::cout << std::fixed << std::setprecision(2);
    std::cout << media << " " << mediana << " " << static_cast<double>(moda) << std::endl;

    return 0;
}
