/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool compareY(const Point& a, const Point& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

double solve(vector<Point>& pts, int l, int r, vector<Point>& stripBuffer) {
    if (r - l <= 3) {
        double d = 1e18;
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                double dx = (double)pts[i].x - pts[j].x;
                double dy = (double)pts[i].y - pts[j].y;
                double cur = sqrt(dx * dx + dy * dy);
                if (cur < d) d = cur;
            }
        }
        sort(pts.begin() + l, pts.begin() + r, compareY);
        return d;
    }

    int mid = l + (r - l) / 2;
    int midX = pts[mid].x;
    double dl = solve(pts, l, mid, stripBuffer);
    double dr = solve(pts, mid, r, stripBuffer);
    double d = min(dl, dr);

    inplace_merge(pts.begin() + l, pts.begin() + mid, pts.begin() + r, compareY);

    int strip_size = 0;
    for (int i = l; i < r; ++i) {
        if (abs(pts[i].x - midX) < d) {
            stripBuffer[strip_size++] = pts[i];
        }
    }

    for (int i = 0; i < strip_size; ++i) {
        for (int j = i + 1; j < strip_size && (double)stripBuffer[j].y - stripBuffer[i].y < d; ++j) {
            double dx = (double)stripBuffer[i].x - stripBuffer[j].x;
            double dy = (double)stripBuffer[i].y - stripBuffer[j].y;
            double curSq = dx * dx + dy * dy;
            if (curSq < d * d) {
                d = sqrt(curSq);
            }
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n < 2) {
        if (n == 1) {
            int x, y;
            cin >> x >> y;
            cout << fixed << setprecision(4) << 0.0000 << endl;
        }
        return 0;
    }

    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts.begin(), pts.end(), compareX);
    
    vector<Point> stripBuffer(n);
    double result = solve(pts, 0, n, stripBuffer);
    
    cout << fixed << setprecision(4) << result << endl;

    return 0;
}