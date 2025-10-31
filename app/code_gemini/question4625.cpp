/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numbers[10];
    for (int i = 0; i < 10; ++i) {
        std::cin >> numbers[i];
    }
    int x;
    std::cin >> x;
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if (numbers[i] == x) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
