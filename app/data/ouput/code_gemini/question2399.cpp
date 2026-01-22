/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int h1, m1, h2, m2;
    std::cin >> h1 >> m1 >> h2 >> m2;

    int inicio_minutos = h1 * 60 + m1;
    int fim_minutos = h2 * 60 + m2;

    int duracao_minutos;

    if (fim_minutos <= inicio_minutos) {
        duracao_minutos = (24 * 60 - inicio_minutos) + fim_minutos;
    } else {
        duracao_minutos = fim_minutos - inicio_minutos;
    }

    int duracao_horas = duracao_minutos / 60;
    int duracao_minutos_resto = duracao_minutos % 60;

    std::cout << "O JOGO DUROU " << duracao_horas << " HORA(S) E " << duracao_minutos_resto << " MINUTO(S)" << std::endl;

    return 0;
}
