/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int IA, IB, FA, FB;
    std::cin >> IA >> IB >> FA >> FB;
    if (IA == FA && IB == FB) {
        std::cout << 0 << std::endl;
    } else if (IA != FA && IB == FB) {
        std::cout << 1 << std::endl;
    } else if (IA != FA && IB != FB) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }
    return 0;
}
