/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double distance(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double calculateRedLength(vector<Point> &points) {
    double totalLength = 0.0;
    bool up = false;

    for (size_t i = 1; i < points.size(); ++i) {
        if ((points[i].y > points[i - 1].y && !up) || (points[i].y < points[i - 1].y && up)) {
            totalLength += distance(points[i - 1], points[i]);
            up = !up;
        }
    }

    return totalLength;
}

int main() {
    int C;
    cin >> C;

    while (C--) {
        int N;
        cin >> N;
        vector<Point> points(N);

        for (int i = 0; i < N; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
            return a.x < b.x;
        });

        double result = calculateRedLength(points);
        cout << fixed << setprecision(2) << result << endl;
    }

    return 0;
}
