/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int nums[3];
    std::cout << "Digite cada numero e pressione ENTER:\n";
    for (int i = 0; i < 3; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums, nums + 3);
    std::cout << "Numeros em ordem crescente:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << nums[i] << "\n";
    }
    return 0;
}
