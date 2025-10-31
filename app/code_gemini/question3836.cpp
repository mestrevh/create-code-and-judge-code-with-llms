/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int tempo;
    std::cin >> tempo;
    if (tempo < 0) {
        std::cout << "Meme man quebrou o tempo! De volta ao transito :(\n";
    } else {
        long long total_horas = 7 + tempo;
        if (total_horas < 62) {
            std::cout << "...Ainda no transito...\n";
        } else {
            int dia_do_ano = (total_horas / 24) + 1;
            if (dia_do_ano == 156) {
                std::cout << "Stonks has been born!\n";
            } else {
                std::cout << "Lar doce lar\n";
            }
        }
    }
    return 0;
}
