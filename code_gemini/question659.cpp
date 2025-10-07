/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int EV1, EV2, AT, D;
    while (std::cin >> EV1 >> EV2 >> AT >> D && (EV1 || EV2 || AT || D)) {
        
        double p = static_cast<double>(AT) / 6.0;
        
        double n1 = std::ceil(static_cast<double>(EV1) / D);
        double n2 = std::ceil(static_cast<double>(EV2) / D);

        if (AT == 3) {
            double prob = n1 / (n1 + n2);
            std::cout << std::fixed << std::setprecision(1) << prob * 100.0 << std::endl;
        } 
        else {
            double q = 1.0 - p;
            double r = q / p;
            
            double prob = (1.0 - std::pow(r, n1)) / (1.0 - std::pow(r, n1 + n2));
            std::cout << std::fixed << std::setprecision(1) << prob * 100.0 << std::endl;
        }
    }

    return 0;
}
