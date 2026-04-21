/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<string> orders;
    unordered_map<string, queue<list<string>::iterator>> iterMap;
    string line;

    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line == "The End") break;
        if (line.empty()) continue;
        
        orders.push_back(line);
        iterMap[line].push(prev(orders.end()));
    }

    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line.empty()) continue;
        
        if (iterMap.count(line) && !iterMap[line].empty()) {
            list<string>::iterator it = iterMap[line].front();
            iterMap[line].pop();
            orders.erase(it);
        }
    }

    if (orders.empty()) {
        cout << "U gotta null pointer ma man" << "\n";
    } else {
        for (const string& item : orders) {
            cout << item << "\n";
        }
    }

    return 0;
}