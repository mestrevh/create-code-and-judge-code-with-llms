/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void printEvenRecursive(int current, int limit) {
    if (current > limit) {
        return;
    }
    std::cout << current << std::endl;
    printEvenRecursive(current + 2, limit);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    printEvenRecursive(0, n);
    return 0;
}
