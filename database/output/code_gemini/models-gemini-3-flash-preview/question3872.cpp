/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

struct Object {
    string name;
    int weight;
    double price;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    if (!(cin >> N >> P)) return 0;

    vector<Point> centers(P);
    for (int i = 0; i < P; ++i) {
        if (!(cin >> centers[i].x >> centers[i].y)) break;
    }

    vector<Object> objs(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> objs[i].name >> objs[i].weight >> objs[i].price)) break;
    }

    sort(objs.begin(), objs.end(), [](const Object& a, const Object& b) {
        return a.name < b.name;
    });

    vector<string> serial_to_name(N);
    vector<bool> used(N, false);

    for (int i = 0; i < N; ++i) {
        long long price_ceil = (long long)ceil(objs[i].price);
        long long alpha_pos = (long long)i;
        long long weight = (long long)objs[i].weight;
        
        long long base_sn = (price_ceil + alpha_pos + weight) % N;
        if (base_sn < 0) base_sn += N;

        int sn = (int)base_sn;
        int k = 0;
        while (used[sn]) {
            k++;
            sn = (int)((base_sn + k) % N);
        }
        used[sn] = true;
        serial_to_name[sn] = objs[i].name;
    }

    vector<Point> vehicle_pos(P);
    for (int i = 0; i < P; ++i) {
        vehicle_pos[i] = centers[i];
    }

    int sn_query;
    while (cin >> sn_query && sn_query != -1) {
        double dx, dy;
        cin >> dx >> dy;

        if (sn_query < 0 || sn_query >= N) continue;

        int items_per_center = N / P;
        int center_idx = sn_query / items_per_center;
        if (center_idx >= P) center_idx = P - 1;

        Point filial_pos = centers[center_idx];

        int best_v = -1;
        double min_dist_sq = -1.0;

        for (int v = 0; v < P; ++v) {
            double diff_x = vehicle_pos[v].x - filial_pos.x;
            double diff_y = vehicle_pos[v].y - filial_pos.y;
            double d2 = diff_x * diff_x + diff_y * diff_y;

            if (best_v == -1 || d2 < min_dist_sq - 1e-11) {
                min_dist_sq = d2;
                best_v = v;
            }
        }

        if (best_v != -1) {
            cout << "delivered " << serial_to_name[sn_query] << " s. " << sn_query << " by vehicle " << best_v + 1 << "\n";
            vehicle_pos[best_v].x = dx;
            vehicle_pos[best_v].y = dy;
        }
    }

    cout << "Thank you for using this service. Bye!" << endl;

    return 0;
}