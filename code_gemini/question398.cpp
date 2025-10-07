/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    int count = 0;
    for (int i = 1; i < 50; ++i) {
        if (i % a == 0 && i % b == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
