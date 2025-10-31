/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> numeros(3);
    std::cin >> numeros[0] >> numeros[1] >> numeros[2];
    std::sort(numeros.begin(), numeros.end());
    std::cout << numeros[1] << std::endl;
    return 0;
}
