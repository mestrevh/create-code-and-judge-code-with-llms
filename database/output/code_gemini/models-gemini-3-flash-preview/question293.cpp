/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;
    if (!(std::cin >> a >> b >> c)) return 0;

    int maiorAB = (a + b + std::abs(a - b)) / 2;
    int maiorABC = (maiorAB + c + std::abs(maiorAB - c)) / 2;

    std::cout << maiorABC << " eh o maior" << std::endl;

    return 0;
}