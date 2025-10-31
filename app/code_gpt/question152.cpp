/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // a) Ordem inversa
    for (int i = n - 1; i >= 0; --i) {
        std::cout << arr[i];
        if (i > 0) std::cout << " ";
    }
    std::cout << std::endl;

    // b) Deslocamento para a esquerda
    for (int i = 1; i < n; ++i) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << " ";
    }
    std::cout << arr[0] << std::endl;

    // c) Ordenado em ordem decrescente
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
