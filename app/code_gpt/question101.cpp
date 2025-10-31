/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool areAligned(vector<pair<int, int>>& points) {
    int x1 = points[0].first, y1 = points[0].second;
    int x2 = points[1].first, y2 = points[1].second;
    for (int i = 2; i < points.size(); i++) {
        int x3 = points[i].first, y3 = points[i].second;
        if ((y2 - y1) * (x3 - x1) != (y3 - y1) * (x2 - x1)) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    while (cin >> N, N != 0) {
        vector<pair<int, int>> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].first >> points[i].second;
        }
        cout << (areAligned(points) ? "ALINHADOS" : "NAO_ALINHADOS") << endl;
    }
    return 0;
}
