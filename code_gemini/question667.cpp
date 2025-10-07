/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, c;
    while (std::cin >> a >> c && (a != 0 || c != 0)) {
        long long total_activations = 0;
        int prev_height = a;
        for (int i = 0; i < c; ++i) {
            int current_height;
            std::cin >> current_height;
            if (current_height < prev_height) {
                total_activations += prev_height - current_height;
            }
            prev_height = current_height;
        }
        std::cout << total_activations << "\n";
    }
    return 0;
}
