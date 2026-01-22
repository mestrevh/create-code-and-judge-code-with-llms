/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, C;
    std::cin >> L >> C;

    int matrix[100][100];
    int count_negative = 0;
    int count_positive = 0;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] < 0) {
                count_negative++;
            } else if (matrix[i][j] > 0) {
                count_positive++;
            }
        }
    }

    std::cout << "Matriz formada:\n";
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << matrix[i][j];
            if (j < C - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    if (L == C && L > 0) {
        long long sum_main = 0;
        long long sum_secondary = 0;
        for (int i = 0; i < L; ++i) {
            sum_main += matrix[i][i];
            sum_secondary += matrix[i][L - 1 - i];
        }
        std::cout << "A diagonal principal e secundaria tem valor(es) " << sum_main << " e " << sum_secondary << " respectivamente.\n";
    } else {
        std::cout << "A diagonal principal e secundaria nao pode ser obtida.\n";
    }

    std::cout << "A matriz possui " << count_negative << " numero(s) menor(es) que zero.\n";
    std::cout << "A matriz possui " << count_positive << " numero(s) maior(es) que zero.\n";

    return 0;
}
