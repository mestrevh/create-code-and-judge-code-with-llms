/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int A, B, C, D;
    while (std::cin >> A >> B >> C >> D) {
        int area1 = A * B;
        int area2 = C * D;
        std::cout << std::max(area1, area2) << std::endl;
    }
    return 0;
}
