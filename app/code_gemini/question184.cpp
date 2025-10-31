/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, A, L, P;
    std::cin >> N;
    std::cin >> A >> L >> P;
    if (N <= A && N <= L && N <= P) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
    return 0;
}
