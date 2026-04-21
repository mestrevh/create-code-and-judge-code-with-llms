/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Domino {
    int first;
    int second;
    bool used;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Domino> vitores(4);
    for (int i = 0; i < 4; ++i) {
        cin >> vitores[i].first >> vitores[i].second;
        vitores[i].used = false;
    }

    vector<Domino> lk(3);
    for (int i = 0; i < 3; ++i) {
        cin >> lk[i].first >> lk[i].second;
        lk[i].used = false;
    }

    for (int r = 0; r < 3; ++r) {
        int move_idx;
        if (!(cin >> move_idx)) break;
        
        Domino v_piece = vitores[move_idx - 1];

        for (int i = 0; i < 3; ++i) {
            if (!lk[i].used) {
                if (lk[i].first == v_piece.first || lk[i].first == v_piece.second || 
                    lk[i].second == v_piece.first || lk[i].second == v_piece.second) {
                    
                    cout << lk[i].first << "-" << lk[i].second << " " << (i + 1) << "\n";
                    lk[i].used = true;
                    break;
                }
            }
        }
    }

    return 0;
}