/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int X, Y;
    std::cin >> X >> Y;
    for (int i = 1; i <= Y; ) {
        for (int j = 0; j < X; ++j) {
            if (i > Y) {
                break;
            }
            if (j > 0) {
                std::cout << " ";
            }
            std::cout << i;
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}
