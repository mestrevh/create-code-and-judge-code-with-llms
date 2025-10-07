/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n % 4 == 0 && n % 7 == 0 && n % 5 != 0) {
        std::cout << "sim" << std::endl;
    } else {
        std::cout << "nao" << std::endl;
    }
    return 0;
}
