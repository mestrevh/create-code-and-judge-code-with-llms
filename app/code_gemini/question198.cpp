/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int prev_t;
    std::cin >> prev_t;

    int total_time = 10;

    for (int i = 1; i < n; ++i) {
        int current_t;
        std::cin >> current_t;
        
        int diff = current_t - prev_t;
        
        if (diff < 10) {
            total_time += diff;
        } else {
            total_time += 10;
        }
        
        prev_t = current_t;
    }

    std::cout << total_time << std::endl;

    return 0;
}
