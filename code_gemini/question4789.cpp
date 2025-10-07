/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int p;
    cin >> p;
    for (int k = 0; k < p; ++k) {
        vector<vector<int>> cols;
        string line;
        while (cin >> line && line != "END") {
            int s, c;
            stringstream ss(line);
            ss >> s;
            cin >> c;
            if (s == 0) {
                cols.insert(cols.begin(), {c});
            } else if (s == cols.size() + 1) {
                cols.push_back({c});
            } else {
                cols[s - 1].push_back(c);
                while (cols[s - 1].size() >= 2 && cols[s - 1].back() == cols[s - 1][cols[s - 1].size() - 2]) {
                    cols[s - 1].pop_back();
                    cols[s - 1].pop_back();
                }
                if (cols[s - 1].empty()) {
                    cols.erase(cols.begin() + s - 1);
                }
            }
        }
        cout << "caso " << k << ":";
        for (const auto& col : cols) {
            if (!col.empty()) {
                cout << " " << col.back();
            }
        }
        cout << endl;
    }
    return 0;
}
