/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pt {
    int x, y;
};

struct Event {
    int x, type, y1, y2, id;
    bool operator<(const Event& other) const {
        if (x != other.x) return x > other.x;
        return type > other.type; // Process Plants (type 1) before Edges (type 0) to ensure x_edge > x_plant
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, V;
    if (!(cin >> P >> V)) return 0;

    vector<Pt> plants(P);
    vector<int> coordsY;
    coordsY.reserve(P + V);
    for (int i = 0; i < P; ++i) {
        cin >> plants[i].x >> plants[i].y;
        coordsY.push_back(plants[i].y);
    }

    vector<Pt> poly(V);
    for (int i = 0; i < V; ++i) {
        cin >> poly[i].x >> poly[i].y;
        coordsY.push_back(poly[i].y);
    }

    sort(coordsY.begin(), coordsY.end());
    coordsY.erase(unique(coordsY.begin(), coordsY.end()), coordsY.end());
    int nY = (int)coordsY.size();

    vector<int> bit(nY + 2, 0);
    auto update = [&](int idx, int val) {
        for (; idx <= nY; idx += idx & -idx) bit[idx] ^= val;
    };
    auto query = [&](int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res ^= bit[idx];
        return res;
    };
    auto get_idx = [&](int y) {
        return (int)(lower_bound(coordsY.begin(), coordsY.end(), y) - coordsY.begin() + 1);
    };

    vector<Event> events;
    events.reserve(P + V);
    for (int i = 0; i < P; ++i) {
        events.push_back({plants[i].x, 1, plants[i].y, 0, i + 1});
    }

    for (int i = 0; i < V; ++i) {
        int next = (i + 1) % V;
        if (poly[i].x == poly[next].x) {
            events.push_back({poly[i].x, 0, min(poly[i].y, poly[next].y), max(poly[i].y, poly[next].y), 0});
        }
    }

    sort(events.begin(), events.end());

    long long outside_sum = 0;
    for (const auto& e : events) {
        if (e.type == 1) { // Plant
            // Ray-casting algorithm: point is inside if intersecting an odd number of edges
            if (query(get_idx(e.y1)) % 2 == 0) {
                outside_sum += e.id;
            }
        } else { // Vertical Edge
            // For a vertical edge between y1 and y2, any plant with y such that y1 < y < y2 
            // and x_plant < x_edge will have this edge as an intersection for its ray.
            int i_low = get_idx(e.y1);
            int i_high = get_idx(e.y2);
            int L = i_low + 1;
            int R = i_high - 1;
            if (L <= R) {
                update(L, 1);
                update(R + 1, 1);
            }
        }
    }

    cout << outside_sum << endl;

    return 0;
}