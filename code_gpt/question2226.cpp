/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::string items[] = {"Life Mushroom", "Fire Flower", "Boost Star", "Mega Mushroom"};
    
    if (N >= 1 && N <= 4) {
        std::cout << items[N - 1] << std::endl;
    }

    return 0;
}
