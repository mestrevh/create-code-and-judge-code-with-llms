/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int total_cobaias = 0;
    int total_coelhos = 0;
    int total_ratos = 0;
    int total_sapos = 0;

    for (int i = 0; i < n; ++i) {
        int quantia;
        char tipo;
        std::cin >> quantia >> tipo;

        total_cobaias += quantia;

        switch (tipo) {
            case 'C':
                total_coelhos += quantia;
                break;
            case 'R':
                total_ratos += quantia;
                break;
            case 'S':
                total_sapos += quantia;
                break;
        }
    }

    std::cout << "Total: " << total_cobaias << " cobaias\n";
    std::cout << "Total de coelhos: " << total_coelhos << "\n";
    std::cout << "Total de ratos: " << total_ratos << "\n";
    std::cout << "Total de sapos: " << total_sapos << "\n";

    double perc_coelhos = (static_cast<double>(total_coelhos) / total_cobaias) * 100.0;
    double perc_ratos = (static_cast<double>(total_ratos) / total_cobaias) * 100.0;
    double perc_sapos = (static_cast<double>(total_sapos) / total_cobaias) * 100.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Percentual de coelhos: " << perc_coelhos << " %\n";
    std::cout << "Percentual de ratos: " << perc_ratos << " %\n";
    std::cout << "Percentual de sapos: " << perc_sapos << " %\n";

    return 0;
}
