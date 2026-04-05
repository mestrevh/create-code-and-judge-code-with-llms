/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x, y;
    if (!(cin >> x >> y)) return 0;

    vector<pair<double,double>> pts(3);
    char name[3] = {'A','B','C'};
    for (int i = 0; i < 3; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    double cx = x, cy = y;
    vector<int> remaining = {0,1,2};
    string order;

    for (int step = 0; step < 3; step++) {
        int best = -1;
        double bestDist = -1;
        for (int idx : remaining) {
            double dx = pts[idx].first - cx;
            double dy = pts[idx].second - cy;
            double dist = sqrt(dx*dx + dy*dy);
            if (best == -1 || dist < bestDist - 1e-12) {
                best = idx;
                bestDist = dist;
            } else if (fabs(dist - bestDist) <= 1e-12) {
                if (name[idx] < name[best]) best = idx;
            }
        }
        if (step) order.push_back(' ');
        order.push_back(name[best]);
        cx = pts[best].first;
        cy = pts[best].second;
        remaining.erase(find(remaining.begin(), remaining.end(), best));
    }

    cout << order << "\n";
    return 0;
}