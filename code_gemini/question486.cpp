/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> numeros;
    int n;
    while (std::cin >> n && n != 99) {
        numeros.push_back(n);
    }
    std::sort(numeros.begin(), numeros.end(), std::greater<int>());
    std::cout << numeros[1] << std::endl;
    return 0;
}
