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
 * Problem: Sunny Mountains
 * The goal is to calculate the total length of the mountain sides illuminated by horizontal 
 * rays from the right during sunset.
 *
 * Algorithm:
 * 1. Sort the given landscape coordinates (peaks and valleys) by their X-coordinate.
 * 2. Scan the points from right to left (from the point with the highest X towards X=0).
 * 3. Keep track of the maximum height (max_h) encountered so far while moving from the right.
 * 4. For each segment between points P[i-1] and P[i], if P[i-1].y is greater than max_h:
 *    - Part of the segment P[i-1]-P[i] is illuminated.
 *    - The illuminated part is the portion of the segment that lies above max_h.
 *    - Calculate the length of this portion using similar triangles.
 *    - Update max_h to P[i-1].y.
 * 5. Sum these lengths and format the output.
 */

struct Point {
    double x, y;
};

// Comparator to sort points based on X coordinate ascending
bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    // Step 1: Sort points by X
    sort(points.begin(), points.end(), comparePoints);
    
    double total_illuminated_length = 0;
    double current_max_height = 0;
    
    // Step 2 & 3: Scan from right to left
    // We start from the rightmost point (index n-1) and check segments to its left.
    for (int i = n - 1; i > 0; --i) {
        // Point p[i-1] is the left point of the segment, p[i] is the right point.
        // Sunlight comes from the right, so a segment is illuminated if its left 
        // point rises above the maximum height seen so far to its right.
        if (points[i - 1].y > current_max_height) {
            double dx = points[i].x - points[i - 1].x;
            double dy = points[i].y - points[i - 1].y;
            
            // Total Euclidean distance of the current segment
            double segment_dist = sqrt(dx * dx + dy * dy);
            
            /**
             * The segment goes from (points[i-1].x, points[i-1].y) to (points[i].x, points[i].y).
             * Only the part from y = current_max_height up to y = points[i-1].y is lit.
             * By similar triangles, the ratio of the illuminated length to the total 
             * segment length is equal to the ratio of the vertical heights.
             * 
             * Note: points[i-1].y > current_max_height >= points[i].y must be true here.
             */
            double illuminated_height = points[i - 1].y - current_max_height;
            double total_segment_height = points[i - 1].y - points[i].y;
            
            total_illuminated_length += segment_dist * (illuminated_height / total_segment_height);
            
            // Step 4: Update the max height seen so far
            current_max_height = points[i - 1].y;
        }
    }
    
    // Step 5: Output formatted to 2 decimal places
    cout << fixed << setprecision(2) << total_illuminated_length << "\n";
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c;
    if (cin >> c) {
        while (c--) {
            solve();
        }
    }
    
    return 0;
}