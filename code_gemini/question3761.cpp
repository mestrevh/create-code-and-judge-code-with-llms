/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int Z, N, X;
    std::cin >> Z >> N >> X;

    std::vector<int> andares(Z + 1, 0);
    for (int i = 0; i < X; ++i) {
        int andar, qtd;
        std::cin >> andar >> qtd;
        if (andar > 0 && andar <= Z) {
            andares[andar] += qtd;
        }
    }

    long long total_percorrido = 0;

    while (true) {
        int andar_mais_alto = 0;
        for (int i = Z; i >= 1; --i) {
            if (andares[i] > 0) {
                andar_mais_alto = i;
                break;
            }
        }

        if (andar_mais_alto == 0) {
            break;
        }

        total_percorrido += 2LL * andar_mais_alto;

        int passageiros_atuais = 0;
        for (int i = andar_mais_alto; i >= 1; --i) {
            if (passageiros_atuais == N) {
                break;
            }
            if (andares[i] > 0) {
                int espaco_disponivel = N - passageiros_atuais;
                int vao_entrar = std::min(andares[i], espaco_disponivel);
                andares[i] -= vao_entrar;
                passageiros_atuais += vao_entrar;
            }
        }
    }

    std::cout << total_percorrido << std::endl;

    return 0;
}
