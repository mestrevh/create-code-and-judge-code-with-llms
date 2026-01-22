/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int vitores_pieces[4][2];
    int lk_pieces[3][2];
    bool lk_used[3] = {false, false, false};

    for (int i = 0; i < 4; ++i) {
        std::cin >> vitores_pieces[i][0] >> vitores_pieces[i][1];
    }

    for (int i = 0; i < 3; ++i) {
        std::cin >> lk_pieces[i][0] >> lk_pieces[i][1];
    }

    for (int round = 0; round < 3; ++round) {
        int v_move_idx;
        std::cin >> v_move_idx;
        v_move_idx--; 

        int end1 = vitores_pieces[v_move_idx][0];
        int end2 = vitores_pieces[v_move_idx][1];

        for (int i = 0; i < 3; ++i) {
            if (!lk_used[i]) {
                int lk1 = lk_pieces[i][0];
                int lk2 = lk_pieces[i][1];

                if (lk1 == end1 || lk1 == end2 || lk2 == end1 || lk2 == end2) {
                    std::cout << lk1 << "-" << lk2 << " " << i + 1 << "\n";
                    lk_used[i] = true;
                    break;
                }
            }
        }
    }

    return 0;
}
