/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long double x, y;
    string sx, sy;
    long double angle;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string content;
    string line;
    while (getline(cin, line)) {
        if (content.empty()) content = line;
        else content += line;
    }

    if (content.empty()) return 0;

    vector<Point> points;
    size_t pos = content.find('*');
    while (pos != string::npos) {
        size_t next_star = content.find('*', pos + 1);
        string segment;
        if (next_star == string::npos) segment = content.substr(pos + 1);
        else segment = content.substr(pos + 1, next_star - (pos + 1));
        
        size_t comma = segment.find(',');
        if (comma != string::npos) {
            string sx = segment.substr(0, comma);
            string sy = segment.substr(comma + 1);
            
            auto trim = [](string& s) {
                size_t first = s.find_first_not_of(" \t\n\r");
                if (first == string::npos) { s = ""; return; }
                size_t last = s.find_last_not_of(" \t\n\r");
                s = s.substr(first, (last - first + 1));
            };
            trim(sx); trim(sy);
            if (!sx.empty() && !sy.empty()) {
                try {
                    points.push_back({stold(sx), stold(sy), sx, sy, 0.0L});
                } catch (...) {}
            }
        }
        pos = next_star;
    }

    if (points.empty()) return 0;

    if (points.size() == 1) {
        cout << "*" << points[0].sx << ", " << points[0].sy << endl;
        return 0;
    }

    long double cx = 0, cy = 0;
    for (const auto& p : points) {
        cx += p.x;
        cy += p.y;
    }
    cx /= (long double)points.size();
    cy /= (long double)points.size();

    for (auto& p : points) {
        p.angle = atan2(p.y - cy, p.x - cx);
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (abs(a.angle - b.angle) > 1e-18)
            return a.angle > b.angle;
        return a.x > b.x;
    });

    int start_idx = 0;
    long double max_x = points[0].x;
    long double max_y = points[0].y;
    for (int i = 1; i < (int)points.size(); ++i) {
        if (points[i].x > max_x || (abs(points[i].x - max_x) < 1e-18 && points[i].y > max_y)) {
            max_x = points[i].x;
            max_y = points[i].y;
            start_idx = i;
        }
    }

    for (int i = 0; i < (int)points.size(); ++i) {
        int idx = (start_idx + i) % (int)points.size();
        cout << "*" << points[idx].sx << ", " << points[idx].sy;
    }
    cout << endl;

    return 0;
}