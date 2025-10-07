/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int neighbors[10][8] = {
    {0, 1, 3},        // 0
    {0, 1, 2, 4},     // 1
    {1, 2, 5},        // 2
    {0, 3, 4, 6},     // 3
    {3, 4, 5, 7},     // 4
    {4, 5, 8},        // 5
    {3, 6, 7, 9},     // 6
    {6, 7, 8},        // 7
    {5, 7, 8, 9},     // 8
    {6, 8, 9}         // 9
};

vector<vector<string>> results;
unordered_set<string> uniqueResults;

void search(int S, int D, string path, int lastDigit, int depth, int &total) {
    if (S == 0 && depth > 0) {
        if (uniqueResults.find(path) == uniqueResults.end()) {
            uniqueResults.insert(path);
            results.push_back(vector<string>(1, path));
            total++;
        }
        return;
    }
    if (depth > 0 && S <= 0) return;

    for (int i = 0; i < 10; ++i) {
        if ((lastDigit == -1 || (depth == 0) || (neighbors[lastDigit][0] == i) || 
            (neighbors[lastDigit][1] == i) || (neighbors[lastDigit][2] == i) || 
            (neighbors[lastDigit][3] == i) || (neighbors[lastDigit][4] == i) || 
            (neighbors[lastDigit][5] == i) || (neighbors[lastDigit][6] == i) || 
            (neighbors[lastDigit][7] == i)) && 
            (path.find('0'+i) == string::npos)) {
            int newSum = S - i;
            if (newSum >= 0) {
                search(newSum, D, path + to_string(i), i, depth + 1, total);
            }
        }
    }
}

int main() {
    int caseNum = 1;
    while (true) {
        int S, D;
        cin >> S >> D;
        if (S == -1 && D == -1) break;

        results.clear();
        uniqueResults.clear();
        int total = 0;

        for (int i = 1; i < 10; ++i) {  // Starting digit must be from 1 to 9
            if (S - i >= 0) {
                search(S - i, D, to_string(i), i, 1, total);
            }
        }

        cout << "#" << caseNum++ << endl;
        if (total == 0) {
            cout << "impossivel\n";
        } else {
            sort(results.begin(), results.end());
            for (const auto& seq : results) {
                cout << seq[0] << endl;
            }
        }
    }
    return 0;
}
