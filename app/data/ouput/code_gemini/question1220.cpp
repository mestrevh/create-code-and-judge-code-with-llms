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

    double sumA = 0.0, sumB = 0.0, sumC = 0.0;
    int countA = 0, countB = 0, countC = 0;

    for (int i = 0; i < n; ++i) {
        char team;
        double power;
        std::cin >> team >> power;

        switch (team) {
            case 'A':
                sumA += power;
                countA++;
                break;
            case 'B':
                sumB += power;
                countB++;
                break;
            case 'C':
                sumC += power;
                countC++;
                break;
        }
    }

    double avgA = (countA > 0) ? sumA / static_cast<double>(countA) : -1e18;
    double avgB = (countB > 0) ? sumB / static_cast<double>(countB) : -1e18;
    double avgC = (countC > 0) ? sumC / static_cast<double>(countC) : -1e18;

    std::cout << std::fixed << std::setprecision(2);

    if (avgA >= avgB && avgA >= avgC) {
        std::cout << "A equipe escolhida foi a A, com media de: " << avgA << std::endl;
    } else if (avgB > avgA && avgB >= avgC) {
        std::cout << "A equipe escolhida foi a B, com media de: " << avgB << std::endl;
    } else {
        std::cout << "A equipe escolhida foi a C, com media de: " << avgC << std::endl;
    }

    return 0;
}
