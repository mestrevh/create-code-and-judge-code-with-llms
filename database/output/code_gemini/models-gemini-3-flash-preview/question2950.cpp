/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problema: L4Q4 - Todo mundo odeia Xadrez
 * Objetivo: Verificar se o rei branco 'K' (de José Gabriel) está em xeque por peças pretas (adversário).
 * Peças: K/k (Rei), Q/q (Rainha), T/t (Torre), B/b (Bispo), C/c (Cavalo), P/p (Peão).
 * José: Maiúsculas. Adversário: Minúsculas.
 */

bool is_inside(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char board[8][8];
    int kr = -1, kc = -1;

    // Leitura do tabuleiro 8x8 e localização do Rei de José (K)
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (!(cin >> board[i][j])) break;
            if (board[i][j] == 'K') {
                kr = i;
                kc = j;
            }
        }
    }

    // Se o Rei não for encontrado (não deve ocorrer baseado na descrição), não há xeque.
    if (kr == -1) {
        cout << "NAO XEQUE" << endl;
        return 0;
    }

    bool is_xeque = false;

    // 1. Verificar ataque de Cavalo adversário ('c')
    int knr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int knc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for (int i = 0; i < 8; ++i) {
        int nr = kr + knr[i], nc = kc + knc[i];
        if (is_inside(nr, nc) && board[nr][nc] == 'c') {
            is_xeque = true;
        }
    }

    // 2. Verificar ataque de Peão adversário ('p')
    // Baseado no Caso de Teste 0, peões pretos atacam para baixo (aumento do índice da linha).
    // Portanto, o Rei em (kr, kc) é atacado por peões em (kr-1, kc-1) ou (kr-1, kc+1).
    if (!is_xeque) {
        if (is_inside(kr - 1, kc - 1) && board[kr - 1][kc - 1] == 'p') is_xeque = true;
        if (is_inside(kr - 1, kc + 1) && board[kr - 1][kc + 1] == 'p') is_xeque = true;
    }

    // 3. Verificar ataque de Rei adversário ('k')
    if (!is_xeque) {
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                int nr = kr + dr, nc = kc + dc;
                if (is_inside(nr, nc) && board[nr][nc] == 'k') is_xeque = true;
            }
        }
    }

    // 4. Verificar ataques em linha reta (Torre 't' ou Rainha 'q')
    if (!is_xeque) {
        int sr[] = {0, 0, 1, -1}, sc[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int nr = kr + sr[i], nc = kc + sc[i];
            while (is_inside(nr, nc)) {
                if (board[nr][nc] != '-') {
                    if (board[nr][nc] == 't' || board[nr][nc] == 'q') is_xeque = true;
                    break; // Caminho bloqueado por qualquer peça
                }
                nr += sr[i]; nc += sc[i];
            }
            if (is_xeque) break;
        }
    }

    // 5. Verificar ataques em diagonais (Bispo 'b' ou Rainha 'q')
    if (!is_xeque) {
        int br[] = {1, 1, -1, -1}, bc[] = {1, -1, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int nr = kr + br[i], nc = kc + bc[i];
            while (is_inside(nr, nc)) {
                if (board[nr][nc] != '-') {
                    if (board[nr][nc] == 'b' || board[nr][nc] == 'q') is_xeque = true;
                    break; // Caminho bloqueado por qualquer peça
                }
                nr += br[i]; nc += bc[i];
            }
            if (is_xeque) break;
        }
    }

    if (is_xeque) {
        cout << "XEQUE" << endl;
    } else {
        cout << "NAO XEQUE" << endl;
    }

    return 0;
}