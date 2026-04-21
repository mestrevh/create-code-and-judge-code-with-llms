/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long max_val = 0;
    long long sum_indices = 0;
    bool initialized = false;

    for (int i = 0; i < 10; ++i) {
        long long current;
        if (!(std::cin >> current)) break;
        
        if (!initialized || current > max_val) {
            max_val = current;
            sum_indices = i;
            initialized = true;
        } else if (current == max_val) {
            sum_indices += i;
        }
    }

    if (initialized) {
        std::cout << sum_indices << std::endl;
    }

    return 0;
}