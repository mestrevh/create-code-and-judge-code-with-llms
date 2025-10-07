/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    
    vector<vector<int>> seats(L, vector<int>(C));
    unordered_map<int, pair<int, int>> original_position;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            seats[i][j] = (i * C) + (j + 1);
            original_position[seats[i][j]] = {i, j};
        }
    }

    vector<vector<int>> final_seats(L, vector<int>(C));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> final_seats[i][j];
        }
    }

    vector<int> row_map(L), col_map(C);
    iota(row_map.begin(), row_map.end(), 0);
    iota(col_map.begin(), col_map.end(), 0);
    
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            int original_num = final_seats[i][j];
            auto [orig_row, orig_col] = original_position[original_num];
            if (orig_row != i) {
                swap(row_map[orig_row], row_map[i]);
            }
            if (orig_col != j) {
                swap(col_map[orig_col], col_map[j]);
            }
        }
    }

    int row_changes = 0, col_changes = 0;
    
    vector<bool> visited_row(L, false), visited_col(C, false);
    
    for (int i = 0; i < L; ++i) {
        if (!visited_row[i]) {
            ++row_changes;
            for (int j = i; !visited_row[j]; j = row_map[j]) {
                visited_row[j] = true;
            }
        }
    }
    
    for (int i = 0; i < C; ++i) {
        if (!visited_col[i]) {
            ++col_changes;
            for (int j = i; !visited_col[j]; j = col_map[j]) {
                visited_col[j] = true;
            }
        }
    }

    cout << (row_changes - 1) + (col_changes - 1) << endl;
    
    return 0;
}
