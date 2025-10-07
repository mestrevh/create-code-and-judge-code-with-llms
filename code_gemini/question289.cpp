/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int F, I;
    std::cin >> F >> I;
    int count = 0;
    if (F >= 150 && I >= 12) {
        count++;
    }
    if (F >= 140 && I >= 14) {
        count++;
    }
    if (F >= 170 || I >= 16) {
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}
