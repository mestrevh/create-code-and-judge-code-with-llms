/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    string dummy;
    getline(cin, dummy); // Consome o newline apos o numero N

    list<string> order;
    unordered_map<string, pair<long long, list<string>::iterator>> house;

    for (int i = 0; i < n; ++i) {
        string line;
        if (!getline(cin, line)) break;
        if (line.empty()) {
            i--; 
            continue;
        }

        if (line.compare(0, 7, "ENTROU:") == 0) {
            string name = line.substr(7);
            long long food;
            if (!(cin >> food)) break;
            getline(cin, dummy); // Consome o newline apos a quantidade de comida

            if (house.find(name) != house.end()) {
                cout << "Anao ja estava em casa." << endl;
            } else {
                cout << name << " entrou e gostaria de " << food << "g de comida." << endl;
                order.push_back(name);
                house[name] = {food, --order.end()};
            }
        } else if (line.compare(0, 5, "SAIU:") == 0) {
            string name = line.substr(5);
            if (house.find(name) != house.end()) {
                cout << name << " saiu de casa." << endl;
                order.erase(house[name].second);
                house.erase(name);
            } else {
                cout << name << " nao estava na casa." << endl;
            }
        }
    }

    cout << "\n";
    if (order.size() == 7) {
        cout << "teoria da branca de neve: porque só ter um se eu posso ter sete." << endl;
    } else {
        cout << "Estao na casa " << order.size() << " anoes:" << endl;
    }

    long long total_food = 0;
    for (const string& name : order) {
        cout << name << endl;
        total_food += house[name].first;
    }
    cout << total_food << endl;

    return 0;
}