/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    int insensibilidade = 0;

    for (int i = 0; i < N; ++i) {
        int X1, Y1, X2, Y2;
        std::cin >> X1 >> Y1 >> X2 >> Y2;
        insensibilidade += (X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1);
    }

    std::cout << insensibilidade << std::endl;
    return 0;
}
