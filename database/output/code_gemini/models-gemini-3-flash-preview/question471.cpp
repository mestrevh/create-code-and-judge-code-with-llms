/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Problema: Pedra, Papel e Tesoura
 * Objetivo: Determinar quem perdeu um campeonato de 5 partidas (sem empates) e deve lavar a louça.
 * Personagens: Miguel e Maria Rita.
 * Vencedor do campeonato: Quem ganhar a maioria das 5 partidas válidas.
 * Saída: Nome do perdedor em letras maiúsculas.
 */

string to_lower_str(string s) {
    for (char &c : s) {
        c = (char)tolower((unsigned char)c);
    }
    return s;
}

int main() {
    // Otimização de I/O padrão Maratona de Programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string escolhaMiguel, escolhaMaria;
    int vitoriasMiguel = 0;
    int vitoriasMaria = 0;
    int partidasValidas = 0;

    // Lemos pares de escolhas até completar 5 partidas sem empate
    while (partidasValidas < 5 && cin >> escolhaMiguel >> escolhaMaria) {
        escolhaMiguel = to_lower_str(escolhaMiguel);
        escolhaMaria = to_lower_str(escolhaMaria);

        // Se houver empate, a partida é ignorada e deve ser jogada novamente
        if (escolhaMiguel == escolhaMaria) {
            continue;
        }

        partidasValidas++;

        // Regras de vitória:
        // - Papel enrola Pedra (Papel ganha)
        // - Pedra amassa Tesoura (Pedra ganha)
        // - Tesoura corta Papel (Tesoura ganha)
        if ((escolhaMiguel == "pedra" && escolhaMaria == "tesoura") ||
            (escolhaMiguel == "papel" && escolhaMaria == "pedra") ||
            (escolhaMiguel == "tesoura" && escolhaMaria == "papel")) {
            vitoriasMiguel++;
        } else {
            vitoriasMaria++;
        }
    }

    // Quem ganhar o jogo NÃO lavará pratos.
    // Se Miguel ganhou mais, Maria lava. Se Maria ganhou mais, Miguel lava.
    if (vitoriasMiguel > vitoriasMaria) {
        cout << "MARIA" << endl;
    } else {
        cout << "MIGUEL" << endl;
    }

    return 0;
}