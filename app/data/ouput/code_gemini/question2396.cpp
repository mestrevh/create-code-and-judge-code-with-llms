/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int s, t, f;
    std::cin >> s >> t >> f;
    int hora_chegada = s + t + f;
    if (hora_chegada >= 24) {
        hora_chegada -= 24;
    } else if (hora_chegada < 0) {
        hora_chegada += 24;
    }
    std::cout << hora_chegada << std::endl;
    return 0;
}
