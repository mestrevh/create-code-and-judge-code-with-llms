/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Find the Convex Hull (minimum subset of trees) for a given set of points.
 * Criteria: 
 * - Output points in counter-clockwise (CCW) order.
 * - Start with the southernmost point (tie-break: westernmost).
 * - Exclude collinear points that are not vertices (corners) of the hull.
 * - Time complexity: O(N log N) using Monotone Chain.
 */

struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

/**
 * cross_product > 0: Left turn (CCW)
 * cross_product < 0: Right turn (CW)
 * cross_product == 0: Collinear
 */
long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> get_hull(vector<Point>& pts) {
    int n = pts.size();
    if (n <= 1) return pts;
    
    // Sort and remove duplicates
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    
    n = pts.size();
    if (n <= 2) return pts;

    vector<Point> h;
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (h.size() >= 2 && cross_product(h[h.size() - 2], h.back(), pts[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(pts[i]);
    }

    // Build upper hull
    int lower_size = (int)h.size();
    for (int i = n - 2; i >= 0; --i) {
        while (h.size() > lower_size && cross_product(h[h.size() - 2], h.back(), pts[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(pts[i]);
    }
    
    // Remove last point because it is the same as the first point
    h.pop_back();
    return h;
}

int main() {
    // Standard CP I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int caseNum = 0;
    while (cin >> N) {
        vector<Point> pts(N);
        for (int i = 0; i < N; ++i) {
            cin >> pts[i].x >> pts[i].y;
        }

        vector<Point> hull = get_hull(pts);

        // Printing results in required format
        cout << "caso " << caseNum++ << ":\n";
        
        if (!hull.empty()) {
            // Find the index of the southernmost (min y) and westernmost (min x) point
            int start_idx = 0;
            for (int i = 1; i < (int)hull.size(); ++i) {
                if (hull[i].y < hull[start_idx].y || (hull[i].y == hull[start_idx].y && hull[i].x < hull[start_idx].x)) {
                    start_idx = i;
                }
            }

            // Print CCW starting from start_idx
            for (int i = 0; i < (int)hull.size(); ++i) {
                int idx = (start_idx + i) % (int)hull.size();
                cout << hull[idx].x << " " << hull[idx].y << "\n";
            }
        }
        
        // Blank line after each case as specified
        cout << "\n";
    }

    return 0;
}