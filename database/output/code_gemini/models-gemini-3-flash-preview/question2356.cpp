/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<long long> numbers;
    long long val;
    
    while (std::cin >> val && val != -1) {
        numbers.push_back(val);
    }

    long long k;
    if (std::cin >> k) {
        int found_index = -1;
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == k) {
                found_index = static_cast<int>(i) + 1;
                break;
            }
        }

        if (found_index != -1) {
            std::cout << "O bilhete sorteado e o " << k << " e esta no carrinho " << found_index << "\n";
        } else {
            std::cout << "Nenhum carrinho foi sorteado\n";
        }
    }

    return 0;
}