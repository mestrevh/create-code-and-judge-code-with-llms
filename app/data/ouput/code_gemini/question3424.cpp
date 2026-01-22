/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int maior = std::numeric_limits<int>::min();
    int posicao = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x > maior) {
            maior = x;
            posicao = i;
        }
    }
    std::cout << "o maior numero eh " << maior << ", e foi lido na posicao " << posicao << std::endl;
    return 0;
}
