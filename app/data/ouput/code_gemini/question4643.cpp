/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char c1, c2, c3, c4, c5;
    std::cin >> c1 >> c2 >> c3 >> c4 >> c5;
    int sum = 0;
    sum += (c1 - 'a' + 1);
    sum += (c2 - 'a' + 1);
    sum += (c3 - 'a' + 1);
    sum += (c4 - 'a' + 1);
    sum += (c5 - 'a' + 1);
    std::cout << sum << std::endl;
    return 0;
}
