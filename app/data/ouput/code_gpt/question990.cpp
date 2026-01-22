/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/cpp
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;
    int cases;
    cin >> cases;
    cin.ignore();

    for (int k = 0; k < cases; ++k) {
        vector<vector<int>> columns;
        
        while (getline(cin, line) && line != "END") {
            istringstream iss(line);
            int S, C;
            iss >> S >> C;

            int idx = S - 1; // Convert to 0-indexed
            if (S == 0) {
                columns.insert(columns.begin(), {C});
            } else if (S == columns.size() + 1) {
                columns.push_back({C});
            } else {
                vector<int>& col = columns[idx];
                col.push_back(C);
                while (col.size() > 1 && col.back() == col[col.size() - 2]) {
                    col.pop_back();
                    if (col.empty()) {
                        columns.erase(columns.begin() + idx);
                        break;
                    }
                }
            }
        }

        cout << "caso " << k << ":";
        for (const auto& col : columns) {
            cout << " " << col.back();
        }
        cout << endl;
    }
    return 0;
}
