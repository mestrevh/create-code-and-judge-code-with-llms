/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

struct City {
    string name;
    int h;
};

void print_pq(const vector<City>& pq) {
    cout << "[";
    for (size_t i = 0; i < pq.size(); ++i) {
        cout << "['" << pq[i].name << "', " << pq[i].h << "]";
        if (i < pq.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string origin, destination;
    if (!(getline(cin, origin))) return 0;
    if (origin.empty()) getline(cin, origin);
    if (!(getline(cin, destination))) return 0;

    map<string, int> heuristics;
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string city;
        int h;
        if (ss >> city >> h) {
            heuristics[city] = h;
        }
    }

    map<string, vector<string>> adj;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string u, v;
        int d;
        if (ss >> u >> v >> d) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<City> pq;
    if (heuristics.count(origin)) {
        pq.push_back({origin, heuristics[origin]});
    }

    vector<string> path;
    while (!pq.empty()) {
        print_pq(pq);
        City curr = pq[0];
        pq.erase(pq.begin());

        if (curr.name == destination) break;

        path.push_back(curr.name);

        if (adj.count(curr.name)) {
            for (const string& neighbor : adj[curr.name]) {
                if (neighbor == origin) continue;

                bool already_in_pq = false;
                for (const auto& city : pq) {
                    if (city.name == neighbor) {
                        already_in_pq = true;
                        break;
                    }
                }

                if (!already_in_pq && heuristics.count(neighbor)) {
                    pq.push_back({neighbor, heuristics[neighbor]});
                }
            }
        }

        stable_sort(pq.begin(), pq.end(), [](const City& a, const City& b) {
            return a.h < b.h;
        });
    }

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}