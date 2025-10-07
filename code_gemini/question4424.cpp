/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int r1, div1, r2, div2, r3, div3;
    std::cin >> r1 >> div1;
    std::cin >> r2 >> div2;
    std::cin >> r3 >> div3;
    for (int x = 1; ; ++x) {
        if (x % div1 == r1 && x % div2 == r2 && x % div3 == r3) {
            std::cout << x << std::endl;
            break;
        }
    }
    return 0;
}
