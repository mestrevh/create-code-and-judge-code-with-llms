/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C, N;
    while (std::cin >> C >> N && (C != -1 || N != -1)) {
        std::vector<int> estacionamento(C, 0);
        std::map<int, std::pair<int, int>> posicoes;
        long long faturamento = 0;

        for (int k = 0; k < N; ++k) {
            char tipo;
            int P;
            std::cin >> tipo >> P;

            if (tipo == 'C') {
                int Q;
                std::cin >> Q;

                int pos_vaga = -1;
                for (int i = 0; i <= C - Q; ++i) {
                    bool espaco_ok = true;
                    for (int j = 0; j < Q; ++j) {
                        if (estacionamento[i + j] != 0) {
                            espaco_ok = false;
                            i += j;
                            break;
                        }
                    }
                    if (espaco_ok) {
                        pos_vaga = i;
                        break;
                    }
                }

                if (pos_vaga != -1) {
                    faturamento += 10;
                    for (int i = 0; i < Q; ++i) {
                        estacionamento[pos_vaga + i] = P;
                    }
                    posicoes[P] = {pos_vaga, Q};
                }

            } else {
                if (posicoes.count(P)) {
                    int start_pos = posicoes[P].first;
                    int length = posicoes[P].second;

                    for (int i = 0; i < length; ++i) {
                        estacionamento[start_pos + i] = 0;
                    }
                    posicoes.erase(P);
                }
            }
        }
        std::cout << faturamento << std::endl;
    }

    return 0;
}
