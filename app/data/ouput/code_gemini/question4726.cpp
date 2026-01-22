/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    if (N % 2 == 0) {
        std::cout << "PAR" << std::endl;
    } else {
        std::cout << "IMPAR" << std::endl;
    }
    return 0;
}
