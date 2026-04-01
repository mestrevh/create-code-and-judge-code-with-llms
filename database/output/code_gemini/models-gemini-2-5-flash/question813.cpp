/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int test_case_num = 1;

    while (std::cin >> N && N != 0) {
        int max_X = std::numeric_limits<int>::min();
        int min_Y = std::numeric_limits<int>::max();
        int min_U = std::numeric_limits<int>::max();
        int max_V = std::numeric_limits<int>::min();

        for (int i = 0; i < N; ++i) {
            int X, Y, U, V;
            std::cin >> X >> Y >> U >> V;

            max_X = std::max(max_X, X);
            min_Y = std::min(min_Y, Y);
            min_U = std::min(min_U, U);
            max_V = std::max(max_V, V);
        }

        std::cout << "Teste " << test_case_num << "\n";
        if (max_X >= min_U || max_V >= min_Y) {
            std::cout << "nenhum\n";
        } else {
            std::cout << max_X << " " << min_Y << " " << min_U << " " << max_V << "\n";
        }
        std::cout << "\n";

        test_case_num++;
    }

    return 0;
}