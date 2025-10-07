/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    bool first_case = true;

    while (std::cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }

        if (!first_case) {
            std::cout << std::endl;
        }

        std::vector<std::string> original_image(N);
        std::cin.ignore(); 

        for (int i = 0; i < N; ++i) {
            std::getline(std::cin, original_image[i]);
        }

        int A, B;
        std::cin >> A >> B;

        int factor_row = A / N;
        int factor_col = B / M;

        for (int i = 0; i < N; ++i) {
            for (int r = 0; r < factor_row; ++r) {
                for (int j = 0; j < M; ++j) {
                    for (int c = 0; c < factor_col; ++c) {
                        std::cout << original_image[i][j];
                    }
                }
                std::cout << std::endl;
            }
        }
        
        first_case = false;
    }

    return 0;
}
