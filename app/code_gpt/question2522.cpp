/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::set<int> A, B, intersecao;
    int num;

    for (int i = 0; i < 5; i++) {
        std::cin >> num;
        A.insert(num);
    }

    for (int i = 0; i < 5; i++) {
        std::cin >> num;
        B.insert(num);
    }

    for (const auto& x : A) {
        if (B.count(x)) {
            intersecao.insert(x);
        }
    }

    for (const auto& x : intersecao) {
        std::cout << x << " ";
    }

    return 0;
}
