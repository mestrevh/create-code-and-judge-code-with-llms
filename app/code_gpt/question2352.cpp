/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void transformaPares(std::vector<int> &L, int n) {
    for (int i = 0; i < n; ++i) {
        if (L[i] % 2 == 0) {
            L[i] += 1;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> L(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }
    
    transformaPares(L, n);

    for (int i = 0; i < n; ++i) {
        std::cout << L[i] << std::endl;
    }
    
    return 0;
}
