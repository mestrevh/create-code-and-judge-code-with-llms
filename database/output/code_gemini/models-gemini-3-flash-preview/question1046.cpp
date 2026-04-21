/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double TVideo, TAudio, TDados, Capacidade;
    while (std::cin >> TVideo >> TAudio >> TDados >> Capacidade) {
        if (Capacidade == 0) continue;
        double QDmax = (TVideo * 5.2 + TAudio * 3.4 + TDados * 1.5) / Capacidade;
        std::cout << std::fixed << std::setprecision(2) << QDmax << "\n";
    }

    return 0;
}