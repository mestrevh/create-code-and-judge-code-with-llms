/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;

    long long x;
    char c;

    vector<pair<char, long long>> inst;
    inst.reserve(q);
    bool anyError = false;

    long long curX = 0;
    int minX = 0, maxX = 0;
    long long y = 0;
    long long yEnd = 0;

    for (int i = 0; i < q; i++) {
        cin >> x >> c;
        inst.push_back({c, x});
        if (c == 'B') {
            y += x;
            yEnd = max(yEnd, y);
        }
    }

    vector<long long> rowPos;
    vector<long long> rowMin, rowMax;

    long long cursorX = 0;
    long long cursorY = 0;

    vector<string> lines;
    lines.reserve((size_t)yEnd + 1);

    for (long long stepY = 0; stepY <= yEnd; stepY++) {
        lines.push_back("");
    }

    auto ensureSize = [&](long long row, long long needMin, long long needMax) {
        if (needMin > needMax) return;
        if ((long long)lines[row].size() == 0) return;
    };

    long long globalMin = 0, globalMax = 0;
    long long tempX = 0;
    long long tempY = 0;
    bool dirH = false;

    for (int i = 0; i < q; i++) {
        char cc = inst[i].first;
        long long xx = inst[i].second;
        if (cc == 'D') {
            globalMax = max(globalMax, tempX + xx);
            tempX += xx;
            globalMin = min(globalMin, tempX);
        } else if (cc == 'E') {
            if (tempX < xx) { anyError = true; break; }
            globalMin = min(globalMin, tempX - xx);
            tempX -= xx;
            globalMax = max(globalMax, tempX);
        } else if (cc == 'B') {
            tempY += xx;
        }
    }

    if (anyError) {
        cout << "Informacao invalida\n";
        return 0;
    }

    int offset = (int)(-globalMin);
    int width = (int)(globalMax - globalMin + 1);

    vector<string> grid((size_t)yEnd + 1, string((size_t)width, ' '));

    long long px = 0, py = 0;

    auto drawDot = [&](long long xcoord, long long ycoord) {
        if (ycoord < 0 || ycoord > yEnd) return;
        long long col = xcoord + offset;
        if (col < 0 || col >= width) return;
        grid[(size_t)ycoord][(size_t)col] = '.';
    };

    for (int i = 0; i < q; i++) {
        char cc = inst[i].first;
        long long xx = inst[i].second;
        if (cc == 'D') {
            for (long long k = 1; k <= xx; k++) {
                px += 1;
                drawDot(px, py);
            }
        } else if (cc == 'E') {
            if (px < xx) {
                cout << "Informacao invalida\n";
                return 0;
            }
            for (long long k = 1; k <= xx; k++) {
                px -= 1;
                drawDot(px, py);
            }
        } else if (cc == 'B') {
            for (long long k = 1; k <= xx; k++) {
                py += 1;
                drawDot(px, py);
            }
        }
    }

    for (size_t i = 0; i < grid.size(); i++) {
        cout << grid[i] << "\n";
    }
    return 0;
}