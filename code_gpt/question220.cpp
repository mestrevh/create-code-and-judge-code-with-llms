/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;
    std::unordered_set<int> presenca;
    for (int i = 0; i < N; ++i) {
        int registro;
        std::cin >> registro;
        presenca.insert(registro);
    }
    std::cout << presenca.size() << std::endl;
    return 0;
}
