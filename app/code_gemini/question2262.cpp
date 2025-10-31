/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int I;
    std::cin >> I;

    std::vector<int> alvo(N);
    for (int i = 0; i < N; ++i) {
        alvo[i] = std::min(i + 1, N - i);
    }

    long long sasuke_score = 0;
    std::set<int> sasuke_hits;
    for (int i = 0; i < I; ++i) {
        int pos;
        std::cin >> pos;
        if (pos >= 1 && pos <= N) {
            if (sasuke_hits.find(pos) == sasuke_hits.end()) {
                sasuke_score += alvo[pos - 1];
                sasuke_hits.insert(pos);
            }
        }
    }

    long long itachi_score = 0;
    std::set<int> itachi_hits;
    for (int i = 0; i < I; ++i) {
        int pos;
        std::cin >> pos;
        if (pos >= 1 && pos <= N) {
            if (itachi_hits.find(pos) == itachi_hits.end()) {
                itachi_score += alvo[pos - 1];
                itachi_hits.insert(pos);
            }
        }
    }

    std::cout << "Sasuke: " << sasuke_score << "\n";
    std::cout << "Itachi: " << itachi_score << "\n";

    if (sasuke_score > itachi_score) {
        std::cout << "Sasuke Uchiha\n";
        if (itachi_score == 0) {
            std::cout << "Um genjutsu desse nivel nao funciona em mim\n";
        }
    } else if (itachi_score > sasuke_score) {
        std::cout << "Itachi Uchiha\n";
        if (sasuke_score == 0) {
            std::cout << "Voce e fraco, lhe falta odio\n";
        }
    } else {
        std::cout << "O empate nunca existiu, voce esta preso num genjutsu\n";
    }

    return 0;
}
