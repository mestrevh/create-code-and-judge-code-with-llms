/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        int hours = n / 3600;
        int minutes = (n % 3600) / 60;
        int seconds = n % 60;
        std::cout << hours << ":" << minutes << ":" << seconds << "\n";
    }

    return 0;
}