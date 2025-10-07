/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int v;
    std::cin >> v;

    int celo_p;
    std::cin >> celo_p;
    long long celo_sum_int = 0;
    for (int i = 0; i < celo_p; ++i) {
        double grade;
        std::cin >> grade;
        celo_sum_int += static_cast<long long>(round(grade * 100.0));
    }

    int c;
    std::cin >> c;

    int celo_rank = 1;
    for (int i = 0; i < c; ++i) {
        int comp_p;
        std::cin >> comp_p;
        long long comp_sum_int = 0;
        for (int j = 0; j < comp_p; ++j) {
            double grade;
            std::cin >> grade;
            comp_sum_int += static_cast<long long>(round(grade * 100.0));
        }

        long long celo_score = celo_sum_int * comp_p;
        long long comp_score = comp_sum_int * celo_p;

        if (comp_score > celo_score) {
            celo_rank++;
        } else if (comp_score == celo_score) {
            if (comp_p > celo_p) {
                celo_rank++;
            }
        }
    }

    if (celo_rank <= v) {
        std::cout << "Matriculado, seu ranking é " << celo_rank << " dentre as " << v << " vagas\n";
    } else {
        std::cout << "Se não tivesse pago Dominó " << celo_p << ", teria entrado...\n";
    }

    return 0;
}
