/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pt {
    long double x, y;
    int sx, sy;
    long double ang;
    string xs, ys;
};

static inline long double normAngle(long double a) {
    const long double PI = acosl(-1.0L);
    while (a < 0) a += 2*PI;
    while (a >= 2*PI) a -= 2*PI;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string all, line;
    while (getline(cin, line)) {
        for (char &c : line) {
            if (c == ',' || c == '-' || c == '+' || c == '.' || isdigit((unsigned char)c)) continue;
            if (isspace((unsigned char)c)) continue;
        }
        all += line;
    }

    all.erase(remove_if(all.begin(), all.end(), [](unsigned char c){ return isspace(c); }), all.end());

    vector<string> tokens;
    string cur;
    for (size_t i = 0; i < all.size(); i++) {
        char c = all[i];
        if (c == '*') {
            if (!cur.empty()) {
                tokens.push_back(cur);
                cur.clear();
            }
            cur.push_back(c);
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) tokens.push_back(cur);

    vector<Pt> pts;
    for (string &t : tokens) {
        if (t.empty()) continue;
        if (t[0] == '*') t = t.substr(1);
        size_t comma = t.find(',');
        if (comma == string::npos) continue;
        string s1 = t.substr(0, comma);
        string s2 = t.substr(comma + 1);
        if (!s1.empty() && (s1[0] == '+')) s1 = s1.substr(1);
        if (!s2.empty() && (s2[0] == '+')) s2 = s2.substr(1);

        Pt p;
        p.x = stold(s1);
        p.y = stold(s2);
        p.ang = 0;
        p.xs = s1;
        p.ys = s2;

        p.sx = (s1.find('e') != string::npos || s1.find('E') != string::npos) ? 0 : 0;
        p.sy = 0;
        pts.push_back(move(p));
    }

    if (pts.empty()) return 0;

    bool hasCommaSpace = true;

    long double cx = 0, cy = 0;
    for (auto &p : pts) { cx += p.x; cy += p.y; }
    cx /= (long double)pts.size();
    cy /= (long double)pts.size();

    for (auto &p : pts) {
        long double dx = p.x - cx;
        long double dy = p.y - cy;
        long double a = atan2l(dy, dx);
        if (a < 0) a += 2*acosl(-1.0L);
        p.ang = a;
    }

    int rightIdx = 0;
    for (int i = 1; i < (int)pts.size(); i++) {
        if (pts[i].x > pts[rightIdx].x) rightIdx = i;
    }

    vector<int> idx(pts.size());
    iota(idx.begin(), idx.end(), 0);

    const long double PI = acosl(-1.0L);
    long double startAng = pts[rightIdx].ang;

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        long double ai = pts[i].ang;
        long double aj = pts[j].ang;
        long double di = ai - startAng;
        long double dj = aj - startAng;
        while (di < 0) di += 2*PI;
        while (dj < 0) dj += 2*PI;
        if (di != dj) return di > dj;
        if (pts[i].x != pts[j].x) return pts[i].x > pts[j].x;
        return pts[i].y > pts[j].y;
    });

    int digitsX = 0, digitsY = 0;
    auto countFrac = [](const string &s) -> int {
        size_t pos = s.find('.');
        if (pos == string::npos) return 0;
        return (int)(s.size() - pos - 1);
    };

    long long n = pts.size();
    for (int k = 0; k < (int)n; k++) {
        int i = idx[k];
        cout << "*" << pts[i].xs << ", " << pts[i].ys;
    }
    cout << "\n";
    return 0;
}