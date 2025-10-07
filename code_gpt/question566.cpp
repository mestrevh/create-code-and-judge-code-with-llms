/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool compareByX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareByY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double closestPairRec(vector<Point>& pointsX, vector<Point>& pointsY) {
    int n = pointsX.size();
    if (n <= 3) {
        double minDist = numeric_limits<double>::max();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                minDist = min(minDist, distance(pointsX[i], pointsX[j]));
        return minDist;
    }

    int mid = n / 2;
    Point midPoint = pointsX[mid];

    vector<Point> leftY, rightY;
    for (const auto& p : pointsY) {
        if (p.x <= midPoint.x) leftY.push_back(p);
        else rightY.push_back(p);
    }

    double leftDist = closestPairRec(pointsX, leftY);
    double rightDist = closestPairRec(vector<Point>(pointsX.begin() + mid, pointsX.end()), rightY);
    double minDist = min(leftDist, rightDist);

    vector<Point> strip;
    for (const auto& p : pointsY) {
        if (abs(p.x - midPoint.x) < minDist) {
            strip.push_back(p);
        }
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

double closestPair(vector<Point>& points) {
    int n = points.size();
    if (n < 2) return numeric_limits<double>::max();
    
    vector<Point> pointsX = points;
    vector<Point> pointsY = points;

    sort(pointsX.begin(), pointsX.end(), compareByX);
    sort(pointsY.begin(), pointsY.end(), compareByY);

    return closestPairRec(pointsX, pointsY);
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        double result = closestPair(points);
        if (result >= 10000) {
            cout << "INFINITY" << endl;
        } else {
            cout << fixed << setprecision(4) << result << endl;
        }
    }
    return 0;
}
