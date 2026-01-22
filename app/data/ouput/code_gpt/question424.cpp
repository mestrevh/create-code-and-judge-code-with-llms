/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        bool allScored = true;
        for (int j = 0; j < M; ++j) {
            int goals;
            std::cin >> goals;
            if (goals == 0) {
                allScored = false;
            }
        }
        if (allScored) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
