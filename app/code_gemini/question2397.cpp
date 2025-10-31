/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    double total = 0.0;
    for (int i = 0; i < n; ++i) {
        int codigo, quantidade;
        std::cin >> codigo >> quantidade;
        switch (codigo) {
            case 1001:
                total += quantidade * 1.50;
                break;
            case 1002:
                total += quantidade * 2.50;
                break;
            case 1003:
                total += quantidade * 3.50;
                break;
            case 1004:
                total += quantidade * 4.50;
                break;
            case 1005:
                total += quantidade * 5.50;
                break;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
