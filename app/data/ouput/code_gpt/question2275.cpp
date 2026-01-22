/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> obstacles(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> obstacles[i];
    }
    
    std::sort(obstacles.begin(), obstacles.end());
    
    int min_force = 1;
    while (true) {
        bool can_jump = true;
        for (int pos = 0; pos < obstacles.size(); pos++) {
            if (obstacles[pos] % min_force == 0) {
                can_jump = false;
                break;
            }
        }
        if (can_jump) {
            std::cout << min_force << std::endl;
            break;
        }
        min_force++;
    }
    
    return 0;
}
