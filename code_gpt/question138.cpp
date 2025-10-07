/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int C, N;
    while (cin >> C >> N, C != -1) {
        vector<int> parking(C, 0);
        unordered_map<int, int> vehicle_map;
        int total_revenue = 0;

        for (int i = 0; i < N; ++i) {
            char action;
            cin >> action;
            if (action == 'C') {
                int plate, length;
                cin >> plate >> length;

                for (int j = 0; j <= C - length; ++j) {
                    bool can_park = true;
                    for (int k = j; k < j + length; ++k) {
                        if (parking[k] != 0) {
                            can_park = false;
                            break;
                        }
                    }
                    if (can_park) {
                        for (int k = j; k < j + length; ++k) {
                            parking[k] = plate;
                        }
                        vehicle_map[plate] = length;
                        total_revenue += 10;
                        break;
                    }
                }
            } else if (action == 'S') {
                int plate;
                cin >> plate;
                if (vehicle_map.count(plate)) {
                    int length = vehicle_map[plate];
                    for (int j = 0; j < C; ++j) {
                        if (parking[j] == plate) {
                            parking[j] = 0;
                        }
                    }
                    vehicle_map.erase(plate);
                }
            }
        }
        cout << total_revenue << endl;
    }
    return 0;
}
