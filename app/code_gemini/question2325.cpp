/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool ehDivisivel(int A, int B) {
    if (B == 0) {
        return false;
    }
    return A % B == 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A, B;
    std::cin >> A >> B;
    if (ehDivisivel(A, B)) {
        std::cout << "divisivel" << '\n';
    } else {
        std::cout << "nao divisivel" << '\n';
    }
    return 0;
}
