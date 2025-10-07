/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <limits>

void print_queue(std::queue<char> q) {
    if (q.empty()) {
        return;
    }
    std::cout << q.front();
    q.pop();
    while (!q.empty()) {
        std::cout << " " << q.front();
        q.pop();
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char startNode, goalNode;
    std::cin >> startNode >> goalNode;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<char, std::set<char>> adj;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        char u, v;
        sscanf(line.c_str(), "%c->%c %*d", &u, &v);
        adj[u].insert(v);
    }

    std::queue<char> q;
    std::map<char, char> parent;
    std::set<char> visited;

    q.push(startNode);
    visited.insert(startNode);
    
    print_queue(q);

    while (!q.empty()) {
        char u = q.front();
        q.pop();

        if (adj.count(u)) {
            for (char v : adj.at(u)) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        
        if (!q.empty()) {
            print_queue(q);
        }
    }

    std::vector<char> path;
    if (visited.count(goalNode)) {
        char curr = goalNode;
        while (curr != startNode) {
            path.push_back(curr);
            curr = parent.at(curr);
        }
        path.push_back(startNode);
        std::reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
