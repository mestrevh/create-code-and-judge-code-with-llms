/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "0") break;
        std::istringstream iss(line);
        int N;
        iss >> N;
        std::vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            iss >> P[i];
        }

        int inversions = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (P[i] > P[j]) {
                    inversions++;
                }
            }
        }

        if (inversions % 2 == 0) {
            std::cout << "Carlos" << std::endl;
        } else {
            std::cout << "Marcelo" << std::endl;
        }
    }
    return 0;
}
