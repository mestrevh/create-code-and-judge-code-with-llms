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

    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "Se a = 0, nao temos uma equacao do segundo grau." << std::endl;
    } else {
        double delta = (b * b) - (4 * a * c);

        // Print coefficients without special formatting first
        std::cout << "Para os seguintes coeficientes: " << a << ", " << b << " e " << c << ". O delta eh: ";
        
        // Now set formatting for delta and the rest of the output
        std::cout << std::fixed << std::setprecision(2) << delta << std::endl;

        if (delta > 0) {
            std::cout << "A equacao possui duas raizes reais distintas." << std::endl;
            double r1 = (-b + std::sqrt(delta)) / (2 * a);
            double r2 = (-b - std::sqrt(delta)) / (2 * a);
            
            // To match the sample output order, print the larger root first.
            if (r1 < r2) {
                double temp = r1;
                r1 = r2;
                r2 = temp;
            }
            std::cout << "As raizes sao: " << r1 << " e " << r2 << std::endl;
        } else if (delta == 0) {
            std::cout << "A equacao possui duas raizes reais iguais." << std::endl;
            double r1 = -b / (2 * a);
            std::cout << "As raizes sao: " << r1 << " e " << r1 << std::endl;
        } else { // delta < 0
            std::cout << "A equacao nao possui raizes reais." << std::endl;
        }
    }

    return 0;
}
