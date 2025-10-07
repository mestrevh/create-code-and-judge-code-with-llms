/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

bool isInsidePolygon(const vector<Point>& polygon, const Point& plant) {
    bool inside = false;
    size_t n = polygon.size();
    for (size_t i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > plant.y) != (polygon[j].y > plant.y)) &&
            (plant.x < (polygon[j].x - polygon[i].x) * (plant.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    int P, V;
    cin >> P >> V;

    vector<Point> plants(P), polygon(V);
    long long totalValue = 0;

    for (int i = 0; i < P; i++) {
        cin >> plants[i].x >> plants[i].y;
        totalValue += (i + 1);
    }

    for (int i = 0; i < V; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    long long outsideValue = 0;

    for (int i = 0; i < P; i++) {
        if (!isInsidePolygon(polygon, plants[i])) {
            outsideValue += (i + 1);
        }
    }

    cout << outsideValue << endl;

    return 0;
}
