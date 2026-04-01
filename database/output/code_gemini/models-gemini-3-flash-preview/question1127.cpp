/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Village {
    long long dist;
    int priority;
    string name;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y, z;
    if (!(cin >> x >> y >> z)) return 0;

    auto calc_dist = [&](long long vx, long long vy, long long vz) {
        return (x - vx) * (x - vx) + (y - vy) * (y - vy) + (z - vz) * (z - vz);
    };

    vector<Village> villages = {
        {calc_dist(140, 200, 456), 0, "Solitude"},
        {calc_dist(0, 64, 10), 1, "Kakariko"},
        {calc_dist(34, 110, 220), 2, "Hogsmeade"}
    };

    sort(villages.begin(), villages.end(), [](const Village& a, const Village& b) {
        if (a.dist != b.dist) return a.dist < b.dist;
        return a.priority < b.priority;
    });

    cout << villages[0].name << " " << villages[1].name << " " << villages[2].name << endl;

    return 0;
}