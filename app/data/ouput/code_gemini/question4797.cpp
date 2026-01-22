/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c;
    int i;
    float f;
    double d;

    std::cin >> c >> i >> f >> d;

    std::cout << std::fixed << std::setprecision(2) << d << " " << f << " " << i << " " << c << std::endl;

    return 0;
}
