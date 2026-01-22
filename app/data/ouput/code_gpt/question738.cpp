/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Edge {
    string destination;
    int interval;
};

struct State {
    string terminal;
    int time;

    bool operator>(const State& other) const {
        return time > other.time;
    }
};

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string O, D;
        int Y, M;
        cin >> O >> D >> Y >> M;

        unordered_map<string, vector<Edge>> graph;

        for (int i = 0; i < M; ++i) {
            string A, B;
            int X;
            cin >> A >> B >> X;
            graph[A].push_back({B, X});
        }

        priority_queue<State, vector<State>, greater<State>> pq;
        unordered_map<string, int> min_time;
        pq.push({O, 0});

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (min_time.find(current.terminal) != min_time.end()) {
                continue;
            }
            min_time[current.terminal] = current.time;

            if (current.terminal == D) {
                cout << "Caso #" << t << ": " << current.time << " anticalmas" << endl;
                break;
            }

            for (const auto& edge : graph[current.terminal]) {
                int wait_time = (current.time % edge.interval == 0) ? 0 : (edge.interval - (current.time % edge.interval));
                int new_time = current.time + wait_time + Y;

                if (min_time.find(edge.destination) == min_time.end()) {
                    pq.push({edge.destination, new_time});
                }
            }
        }

        if (min_time.find(D) == min_time.end()) {
            cout << "Caso #" << t << ": Destino inalcancavel" << endl;
        }
    }
    return 0;
}
