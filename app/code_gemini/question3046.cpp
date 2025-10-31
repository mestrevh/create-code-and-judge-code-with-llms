/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    if (B > C && D > A && (C + D) > (A + B) && C > 0 && D > 0 && A % 2 == 0) {
        std::cout << "Valores aceitos\n";
    } else {
        std::cout << "Valores nao aceitos\n";
    }
    return 0;
}
