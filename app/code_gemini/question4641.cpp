/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h1, m1, h2, m2;
    std::cin >> h1 >> m1;
    std::cin >> h2 >> m2;

    int total_minutos = m1 + m2;
    int horas_extras = total_minutos / 60;
    int minutos_finais = total_minutos % 60;

    int total_horas = h1 + h2 + horas_extras;
    int horas_finais = total_horas % 24;

    std::cout << "Terminarei meu treino por volta das " << horas_finais << " horas e " << minutos_finais << " minutos!" << std::endl;

    return 0;
}
