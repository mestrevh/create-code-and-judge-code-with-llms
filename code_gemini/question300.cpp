/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int altura = 0;
    int posicao_horizontal = 0;
    int sentido = 1;

    const int ALTURA_MAXIMA = 200;
    const int DISTANCIA_MAXIMA = 2000;
    const int MOVIMENTO = 10;

    for (int i = 0; i < n; ++i) {
        char comando;
        std::cin >> comando;

        switch (comando) {
            case 'S':
                if (altura + MOVIMENTO <= ALTURA_MAXIMA) {
                    altura += MOVIMENTO;
                }
                break;

            case 'F':
                if (altura > 0) {
                    int proxima_posicao = posicao_horizontal + MOVIMENTO * sentido;
                    if (std::abs(proxima_posicao) <= DISTANCIA_MAXIMA) {
                        posicao_horizontal = proxima_posicao;
                    }
                }
                break;

            case 'V':
                if (altura > 0) {
                    int proxima_posicao = posicao_horizontal + MOVIMENTO * sentido;
                    if (std::abs(proxima_posicao) <= DISTANCIA_MAXIMA) {
                        posicao_horizontal = proxima_posicao;
                    }
                    sentido *= -1;
                }
                break;

            case 'D':
                if (altura - MOVIMENTO >= 0) {
                    altura -= MOVIMENTO;
                }
                break;
        }
    }

    std::cout << altura << " " << std::abs(posicao_horizontal) << std::endl;

    return 0;
}
