/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Problem: O Campeonato de Vôlei do CIn
 * Strategy: Read 8 team IDs corresponding to A, B, C, D, E, F, G, H.
 * Map each student to their partner and validate all stated conditions.
 * Complexity: O(N log N) where N=8 for reading/counting, O(N^2) for pairing, 
 * but since N is fixed at 8, it's effectively O(1).
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the 8 integers representing team assignments for students A to H
    // A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7
    vector<int> team_id(8);
    map<int, int> counts;
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> team_id[i])) return 0;
        counts[team_id[i]]++;
    }

    // Check if every student has exactly one partner (teams of exactly 2)
    bool valid_formation = true;
    for (auto const& entry : counts) {
        if (entry.second != 2) {
            valid_formation = false;
            break;
        }
    }

    if (!valid_formation) {
        cout << "Alguem nao esta satisfeito..." << endl;
        return 0;
    }

    // Determine the unique partner for each student
    int partner[8];
    for (int i = 0; i < 8; ++i) {
        partner[i] = -1;
        for (int j = 0; j < 8; ++j) {
            if (i != j && team_id[i] == team_id[j]) {
                partner[i] = j;
                break;
            }
        }
    }

    bool satisfied = true;

    // Condition 1: Alan (0) only accepts playing with female (B=1, D=3, F=5, H=7)
    int pA = partner[0];
    if (!(pA == 1 || pA == 3 || pA == 5 || pA == 7)) satisfied = false;

    // Condition 2: Bianca (1) refuses to play with Alan (0) or Daniela (3)
    int pB = partner[1];
    if (pB == 0 || pB == 3) satisfied = false;

    // Condition 3: If Gabriel (6) plays with Helen (7), Daniela (3) must play with Carlos (2)
    if (partner[6] == 7) {
        if (partner[3] != 2) satisfied = false;
    }

    // Condition 4: Helen (7) only plays with Gabriel (6) or Fernanda (5)
    int pH = partner[7];
    if (!(pH == 6 || pH == 5)) satisfied = false;

    // Condition 5 & 6 (Biconditional): 
    // If Carlos (2) plays with Erasmo (4), Fernanda (5) plays with Alan (0).
    // If Carlos (2) plays with anyone else, Fernanda (5) does not play with Alan (0).
    if ((partner[2] == 4) != (partner[5] == 0)) satisfied = false;

    // Output final decision
    if (satisfied) {
        cout << "Conseguimos times suficientes!" << endl;
    } else {
        cout << "Alguem nao esta satisfeito..." << endl;
    }

    return 0;
}