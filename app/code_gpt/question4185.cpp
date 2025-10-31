/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> pares, impares;
    
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        if (num % 2 == 0) {
            pares.push_back(num);
        } else {
            impares.push_back(num);
        }
    }
    
    for (size_t i = 0; i < pares.size(); ++i) {
        std::cout << "pares[" << i << "] = " << pares[i] << std::endl;
    }
    
    for (size_t i = 0; i < impares.size(); ++i) {
        std::cout << "impares[" << i << "] = " << impares[i] << std::endl;
    }
    
    return 0;
}
