/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    while (std::cin >> N && N != 0) {
        int max_strength = 0;
        int count = 0;
        for (int i = 0; i < N; ++i) {
            int current_strength;
            std::cin >> current_strength;
            if (current_strength > max_strength) {
                max_strength = current_strength;
                count = 1;
            } else if (current_strength == max_strength) {
                count++;
            }
        }
        std::cout << max_strength << " " << count << "\n";
    }
    return 0;
}
