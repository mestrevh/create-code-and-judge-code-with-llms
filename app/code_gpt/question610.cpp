/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

long long area(const vector<Point> &polygon) {
    long long a = 0;
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        a += polygon[i].x * polygon[(i + 1) % n].y;
        a -= polygon[i].y * polygon[(i + 1) % n].x;
    }
    return abs(a);
}

int main() {
    int N;
    cin >> N;
    vector<Point> polygon(N);
    for (int i = 0; i < N; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    long long totalArea = area(polygon);
    long long carolVolume = totalArea * 2 / N * (N / 2);
    long long carlaVolume = totalArea * 2 - carolVolume;

    cout << carolVolume << " " << carlaVolume << endl;
    return 0;
}
