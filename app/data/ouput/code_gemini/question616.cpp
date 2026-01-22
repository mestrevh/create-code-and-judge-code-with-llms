/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    int count = 0;
    int guess;
    for (int i = 0; i < 5; ++i) {
        std::cin >> guess;
        if (guess == T) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
