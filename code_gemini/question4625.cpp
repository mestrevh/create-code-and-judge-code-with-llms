/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int nums[10];
    int x;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        std::cin >> nums[i];
    }
    std::cin >> x;
    for (int i = 0; i < 10; i++) {
        if (nums[i] == x) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

