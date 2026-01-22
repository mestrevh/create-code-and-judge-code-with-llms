/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int P;
    cin >> P;
    cin.ignore();
    for (int k = 0; k < P; k++) {
        vector<vector<int>> columns;
        string line;
        while (getline(cin, line) && line != "END") {
            istringstream iss(line);
            int S, C;
            iss >> S >> C;
            if (S == 0) {
                columns.insert(columns.begin(), {C});
            } else if (S == columns.size() + 1) {
                columns.push_back({C});
            } else if (S > 0 && S <= columns.size()) {
                if (!columns[S - 1].empty() && columns[S - 1].back() == C) {
                    columns[S - 1].pop_back();
                } else {
                    columns[S - 1].push_back(C);
                }
            }
            
            while (!columns.empty() && columns.back().empty()) {
                columns.pop_back();
            }
        }
        
        cout << "caso " << k << ":";
        for (int i = 0; i < columns.size(); i++) {
            if (!columns[i].empty()) {
                cout << " " << columns[i].back();
            }
        }
        cout << endl;
    }
    return 0;
}
