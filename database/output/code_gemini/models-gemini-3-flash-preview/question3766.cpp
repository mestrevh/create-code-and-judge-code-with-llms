/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Box {
    long long x, y, z;
    int id;
    bool picked;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n && n != 0) {
        vector<Box> boxes(n);
        for (int i = 0; i < n; ++i) {
            cin >> boxes[i].x >> boxes[i].y >> boxes[i].z;
            boxes[i].id = i + 1;
            boxes[i].picked = false;
        }
        long long cx = 0, cy = 0, cz = 0;
        for (int i = 0; i < n; ++i) {
            int best_idx = -1;
            long long min_d2 = -1;
            for (int j = 0; j < n; ++j) {
                if (!boxes[j].picked) {
                    long long dx = cx - boxes[j].x;
                    long long dy = cy - boxes[j].y;
                    long long dz = cz - boxes[j].z;
                    long long d2 = dx * dx + dy * dy + dz * dz;
                    if (best_idx == -1 || d2 < min_d2 || (d2 == min_d2 && boxes[j].id < boxes[best_idx].id)) {
                        min_d2 = d2;
                        best_idx = j;
                    }
                }
            }
            if (best_idx != -1) {
                boxes[best_idx].picked = true;
                cx = boxes[best_idx].x;
                cy = boxes[best_idx].y;
                cz = boxes[best_idx].z;
                cout << boxes[best_idx].id;
                if (i < n - 1) {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}