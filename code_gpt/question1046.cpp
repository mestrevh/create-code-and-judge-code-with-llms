/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double TVideo, TAudio, TDados, Capacidade;
    std::cin >> TVideo >> TAudio >> TDados >> Capacidade;

    double QDmax = (TVideo * 5.2 + TAudio * 3.4 + TDados * 1.5) / Capacidade;

    std::cout << std::fixed << std::setprecision(2) << QDmax << std::endl;
    return 0;
}
