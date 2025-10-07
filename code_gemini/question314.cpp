/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    while (n--) {
        double c;
        std::cin >> c;
        int dias = 0;
        while (c > 1.0) {
            c /= 2.0;
            dias++;
        }
        std::cout << dias << " dias\n";
    }
    return 0;
}
