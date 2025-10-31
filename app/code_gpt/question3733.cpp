/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <sstream>

using namespace std;

void dfs(char start, char target, map<char, set<char>>& graph) {
    stack<char> s;
    set<char> visited;
    s.push(start);
    
    while (!s.empty()) {
        char node = s.top();
        s.pop();
        
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            cout << node << endl;

            for (const char& neighbor : graph[node]) {
                s.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    string line;
    getline(cin, line);

    char start = line[0];
    getline(cin, line);
    char target = line[0];

    map<char, set<char>> graph;

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        char x, y;
        int d;
        ss >> x;
        ss.ignore(2);
        ss >> y >> d;

        graph[x].insert(y);
        graph[y].insert(x);
    }

    dfs(start, target, graph);
    return 0;
}
