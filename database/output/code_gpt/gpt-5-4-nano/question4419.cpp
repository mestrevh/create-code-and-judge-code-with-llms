/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<char,int>> cmds;
    char c;
    while (cin >> c) {
        if (c == 'x') break;
        int d;
        if (!(cin >> d)) break;
        cmds.push_back({c, d});
    }

    long long y = 0;
    long long maxLeft = 0;
    long long rightCol = 0;

    vector<long long> leftStartY(1, 0), leftEndY(1, 0);
    for (auto &p: cmds) {
        char dir = p.first;
        int dist = (int)p.second;
        if (dir == 'f') {
            y += dist;
        } else if (dir == 'd') {
            rightCol += dist;
        } else if (dir == 'e') {
            leftCol:
            ;
        }
    }

    long long leftColPos = 0;
    long long currLeft = 0;

    long long curY = 0;
    long long minCol = 0;
    long long col = 0;

    for (auto &p: cmds) {
        char dir = p.first;
        int dist = p.second;
        if (dir == 'f') {
            curY += dist;
        } else if (dir == 'd') {
            col += dist;
            rightCol = max(rightCol, col);
        } else if (dir == 'e') {
            col -= dist;
            minCol = min(minCol, col);
        }
    }

    long long totalY = 0;
    col = 0;
    curY = 0;
    minCol = 0;
    rightCol = 0;

    for (auto &p: cmds) {
        char dir = p.first;
        int dist = p.second;
        if (dir == 'f') {
            curY += dist;
        } else if (dir == 'd') {
            col += dist;
            rightCol = max(rightCol, col);
        } else if (dir == 'e') {
            col -= dist;
            minCol = min(minCol, col);
        }
    }
    totalY = curY;

    long long width = 1 + rightCol - minCol;
    long long height = totalY + 1;

    vector<string> grid(height, string(width, ' '));
    long long startCol = -minCol;
    grid[0][startCol] = '.';

    long long yPos = 0;
    long long xPos = 0;

    auto placeArrow = [&](bool right, long long yFrom) {
        // yFrom is current y before movement, and horizontal segment at that y+? in samples is drawn with 1 row per y increment.
        // In samples, horizontal arrows appear on row corresponding to y position after preceding 'f' moves.
        // We'll place at row yFrom.
        int colStart = 0;
        if (right) {
            // arrow '->' size 2 chars
        }
    };

    for (auto &p : cmds) {
        char dir = p.first;
        int dist = p.second;

        if (dir == 'f') {
            for (int i = 0; i < dist; i++) {
                yPos++;
                grid[yPos][xPos - minCol] = '|';
            }
            continue;
        }

        if (dir == 'd') {
            long long fromX = xPos;
            long long toX = xPos + dist;
            long long cFrom = fromX - minCol;
            long long cTo = toX - minCol;

            for (long long c = cFrom + 1; c <= cTo; c++) {
                long long x = c + minCol;
                grid[yPos][c] = '-';
                if (c == cTo) grid[yPos][c-1] = '>';
                else {
                    if (grid[yPos][c] == ' ') grid[yPos][c] = '-';
                }
            }
            if (dist > 0) {
                // build pattern similar to sample: - repeated with -> at end.
                // Ensure last two chars represent '->'
                if (cTo - 1 >= cFrom) grid[yPos][cTo - 1] = '-';
                grid[yPos][cTo] = '>';
                if (cTo-1 >= cFrom) grid[yPos][cTo-1] = '-';
                // place '-' before '>'
                if (cTo-2 >= cFrom) {
                    for (long long cc = cFrom + 1; cc <= cTo - 1; cc++) grid[yPos][cc] = '-';
                }
                // ensure starting position has no arrow head.
                // set the first dash if needed
                if (cFrom + 1 <= cTo - 1) grid[yPos][cFrom + 1] = '-';
                // Put '->' at the end: '-' then '>'
                // Also fill preceding with '-'
                for (long long cc = cFrom + 1; cc <= cTo - 1; cc++) grid[yPos][cc] = '-';
                grid[yPos][cTo] = '>';
            }
            // fix leading char if it should be part of grid '.' existing
            xPos = toX;
            continue;
        }

        if (dir == 'e') {
            long long fromX = xPos;
            long long toX = xPos - dist;
            long long cFrom = fromX - minCol;
            long long cTo = toX - minCol;

            // draw '<' at start of movement in sample looks like '<-' repeated, arrow at end includes '<-'
            for (long long c = cTo; c < cFrom; c++) {
                grid[yPos][c] = '-';
            }
            if (dist > 0) {
                grid[yPos][cTo] = '<';
                if (cTo + 1 <= cFrom - 1) {
                    for (long long cc = cTo + 1; cc <= cFrom - 1; cc++) grid[yPos][cc] = '-';
                }
                if (cTo + 1 <= cFrom) grid[yPos][cTo + 1] = '-';
                // Ensure there is '-' after '<'
                grid[yPos][cTo + 1] = '-';
            }
            xPos = toX;
            continue;
        }
    }

    // Replace '-' around with proper arrowheads for multi-km segments.
    // Samples show for right: "->->->->->" meaning repeating "->" each km.
    // Our simplistic line draws '-' and '>' once. Need exact repetition.
    // Redo properly with second pass on blank grid.

    grid.assign(height, string(width, ' '));
    xPos = 0; yPos = 0;
    grid[0][startCol] = '.';

    auto setRightStep = [&](long long y, long long cFrom) {
        // move one step right: at row y, place '-' at cFrom+1 and '>' at cFrom+1+? to create "->"
    };

    // Draw per 1km: For right, output "->" increases column by 1 but uses 2 characters.
    // However sample seems each km uses 3? Actually sample line: ".                    ->->->->->" implies right arrows are separated by nothing, each km consumes 2 chars ("->").
    // Left uses "<-" similarly.
    // The map seems to be built on a single-character grid for 'f' lines '|', and for 'd'/'e' they use 2-character arrows within same row, with a 1-char spacing due to columns.
    // We'll implement on a character canvas with each km treated as 2 columns for horizontal moves.
    // Rebuild with correct model.

    long long minX = minCol;
    long long maxX = rightCol;
    long long canvasW = 2 * (maxX - minX) + 1;
    vector<string> canvas(height, string(canvasW, ' '));
    long long curX = 0; long long curY2 = 0;
    auto colPos = [&](long long x)->long long{
        return 2 * (x - minX);
    };
    canvas[curY2][colPos(curX)] = '.';

    for (auto &p : cmds) {
        char dir = p.first;
        int dist = p.second;
        if (dir == 'f') {
            for (int i = 0; i < dist; i++) {
                curY2++;
                canvas[curY2][colPos(curX)] = '|';
            }
        } else if (dir == 'd') {
            for (int i = 0; i < dist; i++) {
                long long c = colPos(curX);
                canvas[curY2][c + 1] = '-';
                canvas[curY2][c + 2] = '>';
                curX++;
            }
        } else if (dir == 'e') {
            for (int i = 0; i < dist; i++) {
                long long c = colPos(curX);
                canvas[curY2][c - 1] = '<';
                canvas[curY2][c] = '-';
                curX--;
            }
        }
    }

    canvas[curY2][colPos(curX)] = 'x';

    for (auto &row : canvas) {
        string r = row;
        while (!r.empty() && r.back() == ' ') r.pop_back();
        cout << r << "\n";
    }

    return 0;
}