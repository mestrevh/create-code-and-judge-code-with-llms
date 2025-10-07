/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> x >> y;
    int encrypted_x = (x - 1) + (x + 1);
    int encrypted_y = (y - 1) + (y + 1);
    std::cout << "X = " << std::hex << std::uppercase << encrypted_x << std::endl;
    std::cout << "Y = " << std::hex << std::uppercase << encrypted_y << std::endl;
    return 0;
}
