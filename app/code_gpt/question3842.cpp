/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int a, n;
    std::cin >> a >> n;
    int limit = n * 60;
    int elapsed = 0;

    while (elapsed < limit) {
        if (a == 0) {
            std::cout << elapsed << "\n";
            return 0;
        }
        if (a % 13 == 0) {
            if (a % 60 == 0) {
                a += 30;
            } else {
                a -= 60;
            }
        }
        a++;
        elapsed++;
    }
    
    std::cout << "fui pedir comida mesmo\n";
    return 0;
}
