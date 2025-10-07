/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int V, N;
    std::cin >> V >> N;
    std::vector<int> valores(N);
    for (int i = 0; i < N; i++) {
        std::cin >> valores[i];
    }

    bool pode = false;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (valores[i] + valores[j] + valores[k] == V) {
                    pode = true;
                }
            }
        }
    }

    if (pode) {
        std::cout << "Zeca nao vai ter que trabalhar!";
    } else {
        std::cout << "Zeca vai ter que trabalhar.";
    }
    
    return 0;
}
