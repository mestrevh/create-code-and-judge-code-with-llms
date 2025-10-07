/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        std::vector<int> cpf(11);
        for (int i = 0; i < 9; ++i) {
            std::cin >> cpf[i];
        }

        int sum1 = 0;
        for (int i = 0; i < 9; ++i) {
            sum1 += cpf[i] * (10 - i);
        }
        int rem1 = sum1 % 11;
        cpf[9] = (rem1 < 2) ? 0 : (11 - rem1);

        int sum2 = 0;
        for (int i = 0; i < 10; ++i) {
            sum2 += cpf[i] * (11 - i);
        }
        int rem2 = sum2 % 11;
        cpf[10] = (rem2 < 2) ? 0 : (11 - rem2);

        std::cout << "Caso " << case_num << ": ";
        for (int i = 0; i < 9; ++i) {
            std::cout << cpf[i];
        }
        std::cout << "-" << cpf[9] << cpf[10] << '\n';
    }

    return 0;
}
