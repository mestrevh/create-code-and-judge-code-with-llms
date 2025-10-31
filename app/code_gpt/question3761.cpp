/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int Z, N, X;
    cin >> Z >> N >> X;

    vector<pair<int, int>> requests(X);
    for (int i = 0; i < X; i++) {
        cin >> requests[i].first >> requests[i].second;
    }

    sort(requests.rbegin(), requests.rend());

    int total_distance = 0;
    int current_passengers = 0;

    for (auto& request : requests) {
        int floor = request.first;
        int passengers = request.second;

        while (passengers > 0) {
            if (current_passengers + passengers > N) {
                int can_take = N - current_passengers;
                current_passengers += can_take;
                total_distance += floor * 2;
                passengers -= can_take;
                current_passengers = 0;
            } else {
                current_passengers += passengers;
                total_distance += floor * 2;
                passengers = 0;
            }
        }
    }

    total_distance += current_passengers > 0 ? 0 : 0;
    
    cout << total_distance << endl;

    return 0;
}
