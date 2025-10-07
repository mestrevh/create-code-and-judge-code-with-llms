/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    double total_pessoas = 0.0;
    int total_grupos = 0;

    while (std::cin >> n) {
        total_pessoas += n;
        total_grupos++;
    }

    if (total_grupos > 0) {
        double media = total_pessoas / total_grupos;
        int vitoria_gon = static_cast<int>(total_pessoas) / 2 + 1;

        std::cout << std::fixed << std::setprecision(2) << media << std::endl;
        std::cout << vitoria_gon << std::endl;
    }

    return 0;
}
