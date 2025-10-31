/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C, L, X, Y;
    std::string tipo;

    std::cin >> C >> L >> tipo >> X >> Y;

    bool rebater = false;

    if (tipo == "Saque") {
        if (X >= C / 4.0 && X < C / 2.0 && Y >= 0 && Y <= L) {
            rebater = true;
        }
    } else {
        if (X >= 0 && X < C / 2.0 && Y >= 0 && Y <= L) {
            rebater = true;
        }
    }

    if (rebater) {
        std::cout << "A bola foi rebatida" << std::endl;
    } else {
        std::cout << "A bola foi para fora" << std::endl;
    }

    return 0;
}
