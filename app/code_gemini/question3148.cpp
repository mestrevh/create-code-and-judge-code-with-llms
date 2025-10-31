/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p, n;
    std::cin >> p >> n;
    double m, k;
    std::cin >> m >> k;
    double prob_pegar_na_rua = 1.0 - pow(1.0 - (m * k), p);
    double prob_passar_para_familia = 1.0 - pow(1.0 - k, n);
    double prob_final = prob_pegar_na_rua * prob_passar_para_familia;
    std::cout << std::fixed << std::setprecision(4) << prob_final << std::endl;
    return 0;
}
