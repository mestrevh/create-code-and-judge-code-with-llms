/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numbers[10];
    for (int i = 0; i < 10; ++i) {
        if (!(std::cin >> numbers[i])) break;
    }

    int x;
    if (std::cin >> x) {
        int count = 0;
        for (int i = 0; i < 10; ++i) {
            if (numbers[i] == x) {
                count++;
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}