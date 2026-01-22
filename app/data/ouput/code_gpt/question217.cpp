/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> valores(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> valores[i];
    }
    
    int max_consecutivos = 1, current_consecutivos = 1;
    
    for (int i = 1; i < N; ++i) {
        if (valores[i] == valores[i - 1]) {
            current_consecutivos++;
        } else {
            if (current_consecutivos > max_consecutivos) {
                max_consecutivos = current_consecutivos;
            }
            current_consecutivos = 1;
        }
    }
    
    if (current_consecutivos > max_consecutivos) {
        max_consecutivos = current_consecutivos;
    }
    
    std::cout << max_consecutivos << std::endl;
    return 0;
}
