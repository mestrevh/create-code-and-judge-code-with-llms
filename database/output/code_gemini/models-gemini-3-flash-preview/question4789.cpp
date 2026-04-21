/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    if (!(cin >> P)) return 0;

    for (int caseNum = 0; caseNum < P; ++caseNum) {
        vector<vector<int>> cols;
        string s_str;
        while (cin >> s_str && s_str != "END") {
            int s = stoi(s_str);
            int c;
            cin >> c;

            int n = (int)cols.size();
            if (s == 0) {
                vector<int> newCol;
                newCol.push_back(c);
                cols.insert(cols.begin(), newCol);
            } else if (s == n + 1) {
                vector<int> newCol;
                newCol.push_back(c);
                cols.push_back(newCol);
            } else {
                int idx = s - 1;
                if (idx >= 0 && idx < (int)cols.size()) {
                    if (!cols[idx].empty() && cols[idx].back() == c) {
                        while (!cols[idx].empty() && cols[idx].back() == c) {
                            cols[idx].pop_back();
                        }
                        if (cols[idx].empty()) {
                            cols.erase(cols.begin() + idx);
                        }
                    } else {
                        cols[idx].push_back(c);
                    }
                }
            }
        }

        cout << "caso " << caseNum << ":";
        for (int i = 0; i < (int)cols.size(); ++i) {
            if (!cols[i].empty()) {
                cout << " " << cols[i].back();
            }
        }
        cout << "\n";
    }

    return 0;
}