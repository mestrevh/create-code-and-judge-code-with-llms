/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int Q;
    std::cin >> Q;
    std::vector<int> vehicles(Q);
    
    for (int i = 0; i < Q; ++i) {
        std::cin >> vehicles[i];
    }
    
    int max_length = 1, current_length = 1;

    for (int i = 1; i < Q; ++i) {
        if (vehicles[i] > vehicles[i - 1]) {
            current_length++;
        } else {
            max_length = std::max(max_length, current_length);
            current_length = 1;
        }
    }
    max_length = std::max(max_length, current_length);
    
    std::cout << max_length << std::endl;
    return 0;
}
