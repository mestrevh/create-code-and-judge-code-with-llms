/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y, z;
    std::cin >> x >> y >> z;
    int count = 1;
    for (int i = 1; i <= y; i += z) {
        if (count > 1) {
            std::cout << " ";
        }
        std::cout << i;
        if (count == x) {
            std::cout << "\n";
            count = 1;
        } else {
            count++;
        }
    }
    return 0;
}
