/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int verificaParidade(int x) {
    if (x % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x;
    std::cin >> x;
    std::cout << verificaParidade(x) << std::endl;
    return 0;
}
