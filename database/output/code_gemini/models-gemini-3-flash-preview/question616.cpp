/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    if (!(std::cin >> t)) return 0;
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        int guess;
        std::cin >> guess;
        if (guess == t) {
            count++;
        }
    }
    std::cout << count << "\n";
    return 0;
}