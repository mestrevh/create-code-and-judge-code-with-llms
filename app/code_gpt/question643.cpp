/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Line {
    int x1, y1, x2, y2;

    // Checks if point (px, py) is on this line segment
    bool onSegment(int px, int py) {
        return (min(x1, x2) <= px && px <= max(x1, x2) && min(y1, y2) <= py && py <= max(y1, y2));
    }
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Line> lines(n);
        set<pair<int, int>> points;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points.insert({x, y});
            if (i > 0) {
                lines[i - 1] = {points.begin()->first, points.begin()->second, x, y};
            }
        }
        lines[n - 1] = {points.begin()->first, points.begin()->second, (--points.end())->first, (--points.end())->second};

        set<pair<int, int>> judges;
        for (const auto& line : lines) {
            for (int x = min(line.x1, line.x2); x <= max(line.x1, line.x2); x++) {
                if (!judges.count({x, line.y1}) && !line.onSegment(x, line.y1)) {
                    judges.insert({x, line.y1});
                }
            }
            for (int y = min(line.y1, line.y2); y <= max(line.y1, line.y2); y++) {
                if (!judges.count({line.x1, y}) && !line.onSegment(line.x1, y)) {
                    judges.insert({line.x1, y});
                }
            }
        }

        cout << judges.size() << endl;
    }
    return 0;
}
