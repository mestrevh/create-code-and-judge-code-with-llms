/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double inches;
    std::cin >> inches;
    double millimeters = inches * 25.4;
    std::cout << inches << " polegada(s) eh o mesmo que " << millimeters << " mm" << std::endl;
    return 0;
}
