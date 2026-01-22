/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<vector<int>> all_solutions;
int path[8];

bool can_place(int r, int c) {
    for (int prev_c = 0; prev_c < c; ++prev_c) {
        if (path[prev_c] == r || abs(path[prev_c] - r) == abs(prev_c - c)) {
            return false;
        }
    }
    return true;
}

void generate_all_solutions(int c) {
    if (c == 8) {
        vector<int> current_solution;
        for (int i = 0; i < 8; ++i) {
            current_solution.push_back(path[i] + 1);
        }
        all_solutions.push_back(current_solution);
        return;
    }

    for (int r = 0; r < 8; ++r) {
        if (can_place(r, c)) {
            path[c] = r;
            generate_all_solutions(c + 1);
        }
    }
}

void solve() {
    int r, c;
    cin >> r >> c;

    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";

    int solution_counter = 1;
    for (const auto& sol : all_solutions) {
        if (sol[c - 1] == r) {
            cout << setw(2) << solution_counter++ << "      ";
            for (int i = 0; i < 8; ++i) {
                cout << sol[i] << (i == 7 ? "" : " ");
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generate_all_solutions(0);

    int T;
    cin >> T;

    bool first_case = true;
    while (T--) {
        if (!first_case) {
            cout << "\n";
        }
        solve();
        first_case = false;
    }

    return 0;
}
