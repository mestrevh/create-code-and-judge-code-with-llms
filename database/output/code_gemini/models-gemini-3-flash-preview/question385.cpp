/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string matricula;
    std::string min_matricula;
    double min_cre = std::numeric_limits<double>::max();
    double sum_cre = 0;
    int count = 0;

    while (std::cin >> matricula && matricula != "999") {
        double cre;
        if (!(std::cin >> cre)) break;
        
        if (cre < min_cre) {
            min_cre = cre;
            min_matricula = matricula;
        }
        
        sum_cre += cre;
        count++;
    }

    if (count > 0) {
        std::cout << min_matricula << "\n";
        std::cout << std::fixed << std::setprecision(2) << (sum_cre / count) << "\n";
    }

    return 0;
}

