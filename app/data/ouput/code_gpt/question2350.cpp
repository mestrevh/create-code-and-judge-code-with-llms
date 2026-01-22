/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int maxValor(const std::vector<int>& numeros) {
    int max = numeros[0];
    for (int num : numeros) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numeros(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numeros[i];
    }
    std::cout << maxValor(numeros) << std::endl;
    return 0;
}
