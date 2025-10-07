/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>

bool busca(int x, const std::list<int>& L, int n) {
    for (int elemento : L) {
        if (elemento == x) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    int n;
    std::cin >> n;

    std::list<int> L(n);
    for (int& item : L) {
        std::cin >> item;
    }

    if (busca(x, L, n)) {
        std::cout << "sim\n";
    } else {
        std::cout << "nao\n";
    }

    return 0;
}
