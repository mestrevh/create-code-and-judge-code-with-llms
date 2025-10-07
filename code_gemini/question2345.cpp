/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void verificaRetangulo(int a, int b, int c, int d) {
    std::vector<int> lados = {a, b, c, d};
    std::sort(lados.begin(), lados.end());
    if (lados[0] == lados[1] && lados[2] == lados[3]) {
        std::cout << "formam um retangulo" << std::endl;
    } else {
        std::cout << "nao formam um retangulo" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    verificaRetangulo(a, b, c, d);
    return 0;
}
