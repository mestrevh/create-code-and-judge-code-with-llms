/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct Point {
    double x, y;
};

struct Circle {
    double x, y, r;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W, H, n;
    const double PI = acos(-1.0);
    while (cin >> W >> H >> n && (W || H || n)) {
        vector<Circle> circles(n);
        for (int i = 0; i < n; ++i) {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        set<int> masks;
        auto get_mask = [&](Point p) {
            if (p.x < -1e-7 || p.x > (double)W + 1e-7 || p.y < -1e-7 || p.y > (double)H + 1e-7) return -1;
            int mask_val = 0;
            for (int i = 0; i < n; ++i) {
                double d = dist(p, {circles[i].x, circles[i].y});
                if (d < circles[i].r - 1e-9) {
                    mask_val |= (1 << i);
                }
            }
            return mask_val;
        };

        // All-zeros mask (always exists as circles are strictly inside WxH)
        masks.insert(get_mask({0, 0}));

        for (int i = 0; i < n; ++i) {
            // Check the center of each circle
            int mc = get_mask({circles[i].x, circles[i].y});
            if (mc != -1) masks.insert(mc);
            
            vector<double> angles;
            // Default angles for case with no intersections
            angles.push_back(0);
            angles.push_back(PI);
            angles.push_back(PI / 2.0);
            angles.push_back(1.5 * PI);
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                double dx = circles[j].x - circles[i].x;
                double dy = circles[j].y - circles[i].y;
                double d2 = dx * dx + dy * dy;
                double d = sqrt(d2);
                
                // No intersections
                if (d > circles[i].r + circles[j].r || d < abs(circles[i].r - circles[j].r)) continue;
                
                // Solve for intersection points using circle-circle intersection formula
                double a = (circles[i].r * circles[i].r - circles[j].r * circles[j].r + d2) / (2.0 * d);
                double h2 = circles[i].r * circles[i].r - a * a;
                double h = sqrt(max(0.0, h2));
                
                double x2 = circles[i].x + a * dx / d;
                double y2 = circles[i].y + a * dy / d;
                
                // Representative points near intersections
                angles.push_back(atan2(y2 - h * dx / d - circles[i].y, x2 + h * dy / d - circles[i].x));
                angles.push_back(atan2(y2 + h * dx / d - circles[i].y, x2 - h * dy / d - circles[i].x));
            }
            
            sort(angles.begin(), angles.end());
            vector<double> ua;
            if (!angles.empty()) {
                ua.push_back(angles[0]);
                for (int k = 1; k < (int)angles.size(); ++k) {
                    if (angles[k] - ua.back() > 1e-11) ua.push_back(angles[k]);
                }
            }
            
            // Check points slightly inside and outside each arc on the circle boundary
            for (int k = 0; k < (int)ua.size(); ++k) {
                double nxt = (k + 1 < (int)ua.size()) ? ua[k + 1] : (ua[0] + 2.0 * PI);
                double mid = (ua[k] + nxt) / 2.0;
                for (double dr : {-1e-7, 1e-7}) {
                    double rr = circles[i].r + dr;
                    int m = get_mask({circles[i].x + rr * cos(mid), circles[i].y + rr * sin(mid)});
                    if (m != -1) masks.insert(m);
                }
            }
        }
        
        masks.erase(-1);
        cout << (int)masks.size() << "\n";
    }
    return 0;
}

