/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> teams(8);
    for (int i = 0; i < 8; ++i) {
        std::cin >> teams[i];
    }

    bool isValid = true;

    std::map<int, int> counts;
    for (int team_id : teams) {
        counts[team_id]++;
    }

    if (counts.size() != 4) {
        isValid = false;
    } else {
        for (auto const& pair : counts) {
            if (pair.second != 2) {
                isValid = false;
                break;
            }
        }
    }

    if (isValid) {
        // Player indices: A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7
        // Genders: M=0, F=1.
        const int sex[] = {0, 1, 0, 1, 0, 1, 0, 1}; // A, B, C, D, E, F, G, H

        // Alan (0) só aceita jogar com alguém do sexo feminino.
        int partner_A_idx = -1;
        for (int i = 1; i < 8; ++i) {
            if (teams[i] == teams[0]) {
                partner_A_idx = i;
                break;
            }
        }
        if (sex[partner_A_idx] != 1) {
            isValid = false;
        }

        // Bianca (1) não aceita jogar com Alan (0) nem com Daniela (3).
        if (teams[1] == teams[0] || teams[1] == teams[3]) {
            isValid = false;
        }

        // Se Gabriel (6) jogar com Helen (7), Daniela (3) precisa jogar com Carlos (2).
        bool GH_pair = (teams[6] == teams[7]);
        bool DC_pair = (teams[2] == teams[3]);
        if (GH_pair && !DC_pair) {
            isValid = false;
        }

        // Helen (7) só joga com Gabriel (6) ou Fernanda (5).
        if (teams[7] != teams[6] && teams[7] != teams[5]) {
            isValid = false;
        }

        // (Carlos (2) com Erasmo (4)) se e somente se (Fernanda (5) com Alan (0)).
        bool CE_pair = (teams[2] == teams[4]);
        bool FA_pair = (teams[0] == teams[5]);
        if (CE_pair != FA_pair) {
            isValid = false;
        }
    }

    if (isValid) {
        std::cout << "Conseguimos times suficientes!" << std::endl;
    } else {
        std::cout << "Alguem nao esta satisfeito..." << std::endl;
    }

    return 0;
}
