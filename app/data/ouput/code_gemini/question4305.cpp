/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, y;
    char l;
    int n;

    std::cin >> x >> y >> l >> n;

    if (x < 0.0 || x >= 24.0 || y < 0.0 || y >= 24.0 || x >= y || (l != 'A' && l != 'B') || n <= 0) {
        std::cout << "Entrada Invalida" << std::endl;
        return 0;
    }

    double time_available = y - x;
    double min_time_required;
    bool possible = false;

    if (l == 'A') {
        min_time_required = 1.0;
    } else {
        min_time_required = 0.75;
    }

    if (time_available > min_time_required) {
        if (n <= 5) {
            possible = true;
        } else if (n <= 9 && time_available >= min_time_required * 1.5) {
            possible = true;
        }
    }
    
    if (possible) {
        std::cout << "O uninho faz a boa, obrigado querida mae line" << std::endl;
    } else {
        std::cout << "Infelizmente o uninho nao tanka, rodamos!" << std::endl;
    }

    return 0;
}
