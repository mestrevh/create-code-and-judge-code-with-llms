/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, a, b, c;
    std::cin >> x >> a >> b >> c;
    int cp_naruto = (a + b - c) / 2;
    if (cp_naruto > x) {
        std::cout << "O Pokemon pode ser derrotado!\n";
    } else {
        std::cout << "Melhor nao arriscar\n";
    }
    return 0;
}
