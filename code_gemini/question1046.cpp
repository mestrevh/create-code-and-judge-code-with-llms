/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double tVideo, tAudio, tDados, capacidade;

    std::cin >> tVideo;
    std::cin >> tAudio;
    std::cin >> tDados;
    std::cin >> capacidade;

    double qdmax = (tVideo * 5.2 + tAudio * 3.4 + tDados * 1.5) / capacidade;

    std::cout << std::fixed << std::setprecision(2) << qdmax << std::endl;

    return 0;
}
