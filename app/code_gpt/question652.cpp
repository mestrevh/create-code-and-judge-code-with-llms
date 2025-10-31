/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Flight {
    int destination;
    int seats;
};

int main() {
    int N, M, A;
    while (cin >> N >> M >> A, N || M || A) {
        vector<vector<Flight>> graph(N + 1);
        for (int i = 0; i < M; ++i) {
            int O, D, S;
            cin >> O >> D >> S;
            graph[O].push_back({D, S});
        }

        vector<int> maxSeats(N + 1);
        maxSeats[1] = INT_MAX; // Starting from the first airport

        queue<int> q;
        q.push(1);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (const auto& flight : graph[current]) {
                int availableSeats = min(maxSeats[current], flight.seats);
                if (availableSeats > maxSeats[flight.destination]) {
                    maxSeats[flight.destination] = availableSeats;
                    q.push(flight.destination);
                }
            }
        }

        int trips = (A + *max_element(maxSeats.begin() + 2, maxSeats.end() )) - 1;
        cout << (trips + maxSeats[N] - 1) / maxSeats[N] << endl;
    }
    return 0;
}
