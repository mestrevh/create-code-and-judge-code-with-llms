/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int current_multiple = n;
    while (current_multiple <= m) {
        if (current_multiple % 5 == 0) {
            break;
        }
        current_multiple++;
    }

    if (current_multiple <= m) {
        std::cout << current_multiple;
        current_multiple += 5;
        while (current_multiple <= m) {
            std::cout << "|" << current_multiple;
            current_multiple += 5;
        }
    }

    return 0;
}
