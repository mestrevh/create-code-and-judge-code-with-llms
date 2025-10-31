/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, i;
    std::cin >> n >> i;
    std::vector<int> valores(n);
    
    for (int j = 0; j < n; ++j) {
        std::cin >> valores[j];
    }
    
    std::sort(valores.begin(), valores.end(), std::greater<int>());
    
    std::cout << valores[i - 1] << std::endl;
    return 0;
}
