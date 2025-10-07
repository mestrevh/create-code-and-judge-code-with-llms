/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Spell {
    int mana;
    int damage;
};

struct Monster {
    int health;
    int count;
};

int dijkstra(int start, int end, const vector<vector<int>>& graph, const vector<Monster>& monsters, const vector<Spell>& spells) {
    int n = graph.size();
    vector<int> minMana(n, numeric_limits<int>::max());
    minMana[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentMana, currentNode] = pq.top();
        pq.pop();

        if (currentMana > minMana[currentNode]) continue;

        for (int neighbor : graph[currentNode]) {
            int requiredMana = 0;

            for (const auto& monster : monsters) {
                if (monster.count == 0) continue;
                int health = monster.health;
                int casts = 0;

                while (health > 0) {
                    casts++;
                    health -= spells[0].damage;
                }
                requiredMana += casts * spells[0].mana; // Minimum mana for that monster
            }

            int totalMana = currentMana + requiredMana;
            if (totalMana < minMana[neighbor]) {
                minMana[neighbor] = totalMana;
                pq.push({totalMana, neighbor});
            }
        }
    }
    return minMana[end] == numeric_limits<int>::max() ? -1 : minMana[end];
}

int main() {
    int M, N, G, K;
    while (cin >> M >> N >> G >> K, M || N || G || K) {
        vector<Spell> spells(M);
        for (int i = 0; i < M; ++i) {
            cin >> spells[i].mana >> spells[i].damage;
        }

        vector<vector<int>> graph(N + 1);
        for (int i = 0; i < G; ++i) {
            int A, B;
            cin >> A >> B;
            graph[A].push_back(B);
            graph[B].push_back(A);
        }

        vector<Monster> monsters(N + 1);
        for (int i = 0; i < K; ++i) {
            int room, health;
            cin >> room >> health;
            monsters[room].health += health;
            monsters[room].count++;
        }

        cout << dijkstra(1, N, graph, monsters, spells) << endl;
    }
    return 0;
}
