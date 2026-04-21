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

/**
 * Problem: Sort vertices of a convex polygon in counter-clockwise order.
 * Starting point: Left-most point, then bottom-most point.
 * Time Complexity: O(N log N) due to sorting.
 * Space Complexity: O(N) to store vertices.
 */

struct Point {
    double x, y;
};

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    vector<Point> pts(n);
    double cx = 0, cy = 0;

    // Read points and calculate centroid
    // The centroid of a convex polygon is always interior, 
    // making it a reliable reference point for polar sorting.
    for (int i = 0; i < n; ++i) {
        if (!(cin >> pts[i].x >> pts[i].y)) break;
        cx += pts[i].x;
        cy += pts[i].y;
    }

    cx /= n;
    cy /= n;

    // Sort points by polar angle relative to the centroid
    // atan2 returns angles in the range (-pi, pi], which increases counter-clockwise.
    sort(pts.begin(), pts.end(), [cx, cy](const Point& a, const Point& b) {
        return atan2(a.y - cy, a.x - cx) < atan2(b.y - cy, b.x - cx);
    });

    // Find the starting point according to the rules:
    // 1. Most left (minimum x)
    // 2. Most down (minimum y) if there's a tie in x
    int start_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (pts[i].x < pts[start_idx].x - 1e-11) {
            start_idx = i;
        } else if (abs(pts[i].x - pts[start_idx].x) < 1e-11) {
            if (pts[i].y < pts[start_idx].y - 1e-11) {
                start_idx = i;
            }
        }
    }

    // Output the vertices starting from start_idx in counter-clockwise order
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i) {
        int idx = (start_idx + i) % n;
        cout << pts[idx].x << " " << pts[idx].y << "\n";
    }

    return 0;
}