/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    char foco;
    cin >> foco;

    vector<array<int,4>> bestLineCounts;
    vector<vector<vector<int>>> bestMatrices;

    array<int,4> bestCounts{};
    vector<vector<int>> bestMat;
    bool hasBest = false;

    for (int idx = 0; idx < N; idx++) {
        vector<vector<int>> mat(4, vector<int>(6, 0));
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 6; c++) cin >> mat[r][c];
        }

        array<int,4> counts{};
        for (int r = 0; r < 4; r++) {
            int cnt = 0;
            for (int c = 0; c < 6; c++) cnt += (mat[r][c] != 0);
            counts[r] = cnt;
        }

        int orderFocus = 0;
        int startRow = 0, endRow = 3;
        if (foco == 'A') {
            startRow = 0; endRow = 3; orderFocus = 0;
        } else if (foco == 'M') {
            startRow = 1; endRow = 2; orderFocus = 1;
        } else {
            startRow = 3; endRow = 3; orderFocus = 2;
        }

        int curFocusScore = 0;
        if (foco == 'A') curFocusScore = counts[0];
        else if (foco == 'M') curFocusScore = counts[1] + counts[2];
        else curFocusScore = counts[3];

        array<int,3> formation;
        if (foco == 'A') {
            formation[0] = counts[3];
            formation[1] = counts[1] + counts[2];
            formation[2] = counts[0];
        } else if (foco == 'M') {
            formation[0] = counts[3];
            formation[1] = counts[1] + counts[2];
            formation[2] = counts[0];
        } else {
            formation[0] = counts[3];
            formation[1] = counts[1] + counts[2];
            formation[2] = counts[0];
        }

        int numLines = 0;
        if (counts[3] > 0) numLines = 4;
        else numLines = 3;

        bool better = false;
        if (!hasBest) {
            better = true;
        } else {
            int bestFocusScore = 0;
            if (foco == 'A') bestFocusScore = bestCounts[0];
            else if (foco == 'M') bestFocusScore = bestCounts[1] + bestCounts[2];
            else bestFocusScore = bestCounts[3];

            if (curFocusScore != bestFocusScore) {
                better = (curFocusScore > bestFocusScore);
            } else {
                int curTotal = counts[0] + counts[1] + counts[2] + counts[3];
                int bestTotal = bestCounts[0] + bestCounts[1] + bestCounts[2] + bestCounts[3];
                if (curTotal != bestTotal) better = (curTotal > bestTotal);
                else {
                    array<int,3> curForm = {formation[0], formation[1], formation[2]};
                    array<int,3> bestForm = { (foco=='A'||foco=='M'||foco=='D') ? bestCounts[3] : bestCounts[3],
                                              bestCounts[1] + bestCounts[2],
                                              bestCounts[0]};
                    if (curForm != bestForm) better = (curForm > bestForm);
                }
            }
        }

        if (better) {
            hasBest = true;
            bestCounts = counts;
            bestMat = mat;
        }
    }

    int defCnt = bestCounts[3];
    int midCnt = bestCounts[1] + bestCounts[2];
    int atkCnt = bestCounts[0];

    string form;
    if (defCnt > 0) {
        if (midCnt == 0) {
            form = to_string(defCnt) + "-0-" + to_string(atkCnt);
        } else {
            form = to_string(defCnt) + "-" + to_string(midCnt) + "-" + to_string(atkCnt);
        }
    } else {
        form = to_string(0) + "-" + to_string(midCnt) + "-" + to_string(atkCnt);
    }

    cout << "Pipi e Mariozito deviam escolher a formacao " << form << "\n";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 6; c++) {
            cout << bestMat[r][c] << (c == 5 ? ' ' : ' ');
        }
        cout << "\n";
    }
    for (int r = 3; r < 4; r++) {
        for (int c = 0; c < 6; c++) {
            cout << bestMat[r][c] << (c == 5 ? ' ' : ' ');
        }
        if (true) cout << "\n";
    }
    return 0;
}