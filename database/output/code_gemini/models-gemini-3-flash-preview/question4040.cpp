/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    char F;
    cin >> F;

    int best_val = -1;
    string best_name = "";
    int best_mat[4][6];

    for (int i = 0; i < N; ++i) {
        int mat[4][6];
        int s[4] = {0, 0, 0, 0};
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 6; ++c) {
                if (!(cin >> mat[r][c])) break;
                s[r] += mat[r][c];
            }
        }

        int focus_val = 0;
        string name = "";
        
        // Matrix order: s[0]=Ataque, s[1]=Meio1, s[2]=Meio2, s[3]=Defesa
        // Rule: 3-line if s[0] == 0, else 4-line
        if (s[0] == 0) {
            // 3-line: Defense-Mid-Attack (s[3]-s[2]-s[1])
            name = to_string(s[3]) + "-" + to_string(s[2]) + "-" + to_string(s[1]);
            if (F == 'D') focus_val = s[3];
            else if (F == 'M') focus_val = s[2];
            else if (F == 'A') focus_val = s[1];
        } else {
            // 4-line: Defense-Mid1-Mid2-Attack (s[3]-s[2]-s[1]-s[0])
            name = to_string(s[3]) + "-" + to_string(s[2]) + "-" + to_string(s[1]) + "-" + to_string(s[0]);
            if (F == 'D') focus_val = s[3];
            else if (F == 'M') focus_val = max(s[1], s[2]);
            else if (F == 'A') focus_val = s[0];
        }

        if (focus_val > best_val) {
            best_val = focus_val;
            best_name = name;
            for (int r = 0; r < 4; ++r) {
                for (int c = 0; c < 6; ++c) {
                    best_mat[r][c] = mat[r][c];
                }
            }
        }
    }

    if (best_val != -1) {
        cout << "Pipi e Mariozito deviam escolher a formacao " << best_name << "\n";
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 6; ++c) {
                cout << best_mat[r][c] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}