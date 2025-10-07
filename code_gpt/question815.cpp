/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int IA, IB, FA, FB;
    std::cin >> IA >> IB >> FA >> FB;

    int count = 0;

    if (IA != FA) count++; // C1 action
    if (IB != FB) count += 1; // If FB is different, C2 action
    if (FA != FB) count++; // If final states are different, additional C2 action

    std::cout << count << std::endl;
    return 0;
}
