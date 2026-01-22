/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    std::cin >> a >> b >> c;
    int cakes_from_flour = a / 2;
    int cakes_from_eggs = b / 3;
    int cakes_from_milk = c / 5;
    int max_cakes = std::min({cakes_from_flour, cakes_from_eggs, cakes_from_milk});
    std::cout << max_cakes << "\n";
    return 0;
}
