/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> lines;
    string line;
    while (true) {
        string s;
        if (!getline(cin, s)) break;
        bool any = false;
        for (char c : s) if (!isspace((unsigned char)c)) { any = true; break; }
        if (!any) continue;
        lines.push_back(s);
    }
    if (lines.empty()) return 0;

    auto trim = [](string a) {
        size_t i = 0;
        while (i < a.size() && isspace((unsigned char)a[i])) i++;
        size_t j = a.size();
        while (j > i && isspace((unsigned char)a[j-1])) j--;
        return a.substr(i, j - i);
    };

    char dir = 0;
    long long steps = 0;
    vector<pair<char,long long>> ops;
    for (string s : lines) {
        s = trim(s);
        if (s.empty()) continue;
        if (s == "x" || s == "X") break;
        stringstream ss(s);
        char c; long long v;
        if (ss >> c >> v) ops.push_back({c, v});
    }

    long long total = 0;
    for (auto &p : ops) total += p.second;

    if (ops.empty()) return 0;

    long long cx = 0, cy = 0;
    vector<pair<long long,long long>> path;
    path.push_back({cx,cy});

    auto moveStep = [&](long long sx, long long sy){
        cx += sx; cy += sy;
        path.push_back({cx,cy});
    };

    for (auto &op : ops) {
        char d = op.first;
        long long k = op.second;
        for (long long i = 0; i < k; i++) {
            if (d == 'd') moveStep(1,0);
            else if (d == 'e') moveStep(-1,0);
            else if (d == 'f') moveStep(0,-1);
            else if (d == 'x') break;
            else if (d == 'c') moveStep(0,1);
            else if (d == 'u') moveStep(0,-1);
            else if (d == 'b') moveStep(0,1);
            else if (d == 's') moveStep(0,1);
            else moveStep(0,0);
        }
    }

    long long minX = path[0].first, maxX = path[0].first;
    long long minY = path[0].second, maxY = path[0].second;
    for (auto &p : path) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    int W = (int)(maxX - minX + 1);
    int H = (int)(maxY - minY + 1);
    vector<string> grid(H, string(W, ' '));

    auto setCell = [&](long long x, long long y, char ch){
        int gx = (int)(x - minX);
        int gy = (int)(y - minY);
        if (gy >= 0 && gy < H && gx >= 0 && gx < W) grid[gy][gx] = ch;
    };

    for (size_t i = 0; i < path.size(); i++) {
        long long x = path[i].first, y = path[i].second;
        bool start = (i==0);
        bool end = (i+1==path.size());
        if (start) setCell(x,y,'.');
        else if (end) setCell(x,y,'x');
        else setCell(x,y,'|');
    }

    for (size_t i = 1; i < path.size(); i++) {
        long long x1 = path[i-1].first, y1 = path[i-1].second;
        long long x2 = path[i].first, y2 = path[i].second;
        if (x1 == x2) {
            long long yStart = min(y1,y2), yEnd = max(y1,y2);
            for (long long y = yStart; y <= yEnd; y++) {
                if (grid[(int)(y - minY)][(int)(x1 - minX)] == ' ' || grid[(int)(y - minY)][(int)(x1 - minX)] == '.')
                    grid[(int)(y - minY)][(int)(x1 - minX)] = '|';
            }
        } else if (y1 == y2) {
            long long xStart = min(x1,x2), xEnd = max(x1,x2);
            for (long long x = xStart; x <= xEnd; x++) {
                if (grid[(int)(y1 - minY)][(int)(x - minX)] == ' ' || grid[(int)(y1 - minY)][(int)(x - minX)] == '.')
                    grid[(int)(y1 - minY)][(int)(x - minX)] = '-';
            }
        }
    }

    for (auto &row : grid) cout << row << "\n";
    return 0;
}