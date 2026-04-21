/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FastInput {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastInput() : idx(0), size(0) {}
    inline char read() {
        if (size == idx) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }
    template<class T>
    bool readInt(T &out) {
        char c;
        do { c = read(); if (!c) return false; } while (c <= ' ');
        bool neg = false;
        if (c == '-') { neg = true; c = read(); }
        T val = 0;
        while (c > ' ') {
            val = val * 10 + (c - '0');
            c = read();
        }
        out = neg ? -val : val;
        return true;
    }
    bool readLine(string &s) {
        s.clear();
        char c = read();
        if (!c) return false;
        while (c == '\r') c = read();
        while (c != 0 && c != '\n') {
            if (c != '\r') s.push_back(c);
            c = read();
        }
        return true;
    }
};

static const long long INFLL = (1LL<<62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FastInput in;
    int S, L, C;
    while (true) {
        if (!in.readInt(S)) return 0;
        in.readInt(L);
        in.readInt(C);
        if (S == 0) break;

        vector<int> rowCost(L), colCost(C);
        for (int i = 0; i < L; i++) rowCost[i] = (i + 1);
        for (int j = 0; j < C; j++) colCost[j] = (j + 1);

        vector<long long> rowSum(L, 0), colSum(C, 0);
        for (int i = 0; i < L; i++) rowSum[i] = rowCost[i];
        for (int j = 0; j < C; j++) colSum[j] = colCost[j];

        struct CellValue { int r, c; int w; };
        int N = L * C;

        vector<long long> freq(256, 0);
        vector<long long> totalCostPos(N, 0);

        vector<string> sentences;
        sentences.reserve(S);

        bool needConsumeEmpty = false;
        char ch;
        do { ch = in.read(); } while (ch && ch != '\n');
        if (!ch) return 0;

        for (int si = 0; si < S; si++) {
            string line;
            in.readLine(line);
            sentences.push_back(line);
            for (unsigned char uc : line) freq[uc]++;
        }

        long long maxFreq = 0;
        for (int k = 0; k < 256; k++) maxFreq = max(maxFreq, freq[k]);

        int totalLen = 0;
        for (int k = 0; k < 256; k++) totalLen += (int)freq[k];

        vector<int> blankRowCount(L, 0), blankColCount(C, 0);

        vector<int> cntRow(L, 0), cntCol(C, 0);

        vector<long long> answer(S, 0);

        vector<int> rowOrder(L), colOrder(C);
        iota(rowOrder.begin(), rowOrder.end(), 0);
        iota(colOrder.begin(), colOrder.end(), 0);

        vector<int> rowRev(L), colRev(C);
        for (int i = 0; i < L; i++) rowRev[i] = i;
        for (int j = 0; j < C; j++) colRev[j] = j;

        for (int si = 0; si < S; si++) {
            string &line = sentences[si];
            vector<int> path(0);
            vector<int> needed(256, 0);
            for (unsigned char uc : line) needed[uc]++;

            vector<int> chars;
            chars.reserve(256);
            for (int k = 0; k < 256; k++) if (needed[k]) chars.push_back(k);

            vector<int> spaces = { ' ' };
            (void)spaces;

            long long blanks = needed[(unsigned char)' '];
            long long nonblanks = (long long)line.size() - blanks;

            vector<long long> wRow(L, 0), wCol(C, 0);
            for (int i = 0; i < L; i++) wRow[i] = 0;
            for (int j = 0; j < C; j++) wCol[j] = 0;

            vector<int> multRow(L, 1), multCol(C, 1);

            for (int i = 0; i < L; i++) wRow[i] = i + 1;
            for (int j = 0; j < C; j++) wCol[j] = j + 1;

            vector<int> freqChars(256, 0);
            for (int k = 0; k < 256; k++) freqChars[k] = needed[k];

            vector<long long> posScore(256, 0);

            int r = L, c = C;

            auto computeMinimum = [&](int nRows, int nCols, const vector<int>& counts)->long long{
                long long nonBlankCount = (long long)line.size() - counts[(unsigned char)' '];
                if (nonBlankCount == 0) return 0;

                int totalCells = nRows * nCols;
                vector<long long> rowWeight(nRows), colWeight(nCols);
                for (int i = 0; i < nRows; i++) rowWeight[i] = i + 1;
                for (int j = 0; j < nCols; j++) colWeight[j] = j + 1;

                vector<long long> values;
                values.reserve(totalCells);
                for (int i = 0; i < nRows; i++)
                    for (int j = 0; j < nCols; j++)
                        values.push_back(rowWeight[i] + colWeight[j]);
                sort(values.begin(), values.end());

                vector<long long> t(256, 0);
                for (int k = 0; k < 256; k++) t[k] = counts[k];

                long long blanksCnt = t[(unsigned char)' '];
                vector<int> activeChars;
                activeChars.reserve(256);
                for (int k = 0; k < 256; k++) if (t[k] > 0 && k != (int)' ') activeChars.push_back(k);

                vector<long long> charFreq;
                charFreq.reserve(activeChars.size());
                for (int k : activeChars) charFreq.push_back(t[k]);

                sort(charFreq.begin(), charFreq.end(), greater<long long>());

                int distinct = (int)charFreq.size();
                if (distinct == 0) return 0;

                int need = (int)nonBlankCount;
                long long res = 0;

                int idx = 0;
                vector<int> usedCellsByChar(totalCells, 0);
                (void)usedCellsByChar;

                vector<long long> rowBest(nRows, 0), colBest(nCols, 0);
                (void)rowBest; (void)colBest;

                vector<int> sizes(distinct, 0);
                for (int i = 0; i < distinct; i++) sizes[i] = (int)charFreq[i];

                vector<int> assignmentSizes(distinct, 0);
                for (int i = 0; i < distinct; i++) assignmentSizes[i] = sizes[i];

                int m = distinct;
                int kpos = 0;
                for (int i = 0; i < m; i++) {
                    int f = assignmentSizes[i];
                    for (int t = 0; t < f; t++) {
                        if (idx >= (int)values.size()) break;
                        res += values[idx++];
                    }
                }

                return res;
            };

            long long cost = computeMinimum(L, C, freqChars);

            answer[si] = cost;
        }

        for (int i = 0; i < S; i++) {
            cout << answer[i] << "\n";
        }
    }
    return 0;
}