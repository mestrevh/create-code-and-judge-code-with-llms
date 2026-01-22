/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>

bool busca(int x, const std::list<int>& L) {
    for (int num : L) {
        if (num == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, n;
    std::cin >> x >> n;
    std::list<int> L;
    L.resize(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> *(std::next(L.begin(), i));
    }
    
    std::cout << (busca(x, L) ? "sim" : "nao") << std::endl;
    return 0;
}
