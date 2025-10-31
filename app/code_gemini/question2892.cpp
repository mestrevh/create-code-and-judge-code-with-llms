/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << "Digite a ordem N da matriz:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            if (i == j) {
                value = 1;
            } else if (i < j) {
                value = 10;
            } else {
                value = -10;
            }
            std::cout << std::left << std::setw(7) << value;
        }
        std::cout << std::endl;
    }
    return 0;
}
