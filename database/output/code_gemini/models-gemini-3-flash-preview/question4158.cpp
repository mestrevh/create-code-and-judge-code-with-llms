/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    char name;
    double x, y;
    bool visited;
};

double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double current_x, current_y;
    if (!(cin >> current_x >> current_y)) return 0;

    vector<Point> points(3);
    char names[] = {'A', 'B', 'C'};
    for (int i = 0; i < 3; ++i) {
        points[i].name = names[i];
        cin >> points[i].x >> points[i].y;
        points[i].visited = false;
    }

    for (int i = 0; i < 3; ++i) {
        int best_idx = -1;
        double min_dist = -1.0;

        for (int j = 0; j < 3; ++j) {
            if (points[j].visited) continue;

            double d = calculate_distance(current_x, current_y, points[j].x, points[j].y);

            if (best_idx == -1 || d < min_dist - 1e-11) {
                min_dist = d;
                best_idx = j;
            } else if (abs(d - min_dist) < 1e-11) {
                if (points[j].name < points[best_idx].name) {
                    best_idx = j;
                }
            }
        }

        if (best_idx != -1) {
            points[best_idx].visited = true;
            current_x = points[best_idx].x;
            current_y = points[best_idx].y;
            cout << points[best_idx].name << (i == 2 ? "" : " ");
        }
    }
    cout << endl;

    return 0;
}

