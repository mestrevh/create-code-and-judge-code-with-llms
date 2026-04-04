/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int verificar_paridade(long long n) {
    if (n < 0) n = -n;
    return (n % 2 == 0) ? 1 : 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        if (verificar_paridade(n) == 1) {
            std::cout << "par" << std::endl;
        } else {
            std::cout << "nao par" << std::endl;
        }
    }

    return 0;
}