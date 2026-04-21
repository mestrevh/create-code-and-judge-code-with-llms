/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, m;
    if (std::cin >> h >> m) {
        int total_minutos = (h * 60) + m;
        std::cout << total_minutos << " minutos.\n";
    }

    return 0;
}