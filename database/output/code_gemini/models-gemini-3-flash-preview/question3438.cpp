/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);

    unordered_map<string, unordered_set<string>> supermarket;

    for (int i = 0; i < n; ++i) {
        string sectionName;
        if (!getline(cin, sectionName)) break;
        
        string itemsLine;
        if (!getline(cin, itemsLine)) break;
        
        unordered_set<string> items;
        stringstream ss(itemsLine);
        string item;
        while (ss >> item) {
            items.insert(item);
        }
        supermarket[sectionName] = items;
    }

    string queryLine;
    while (getline(cin, queryLine) && queryLine != "FIM") {
        if (queryLine.empty()) continue;
        
        size_t commaPos = queryLine.find(',');
        if (commaPos != string::npos) {
            string qSection = queryLine.substr(0, commaPos);
            string qItem = queryLine.substr(commaPos + 1);
            
            auto it = supermarket.find(qSection);
            if (it != supermarket.end()) {
                if (it->second.find(qItem) != it->second.end()) {
                    cout << "Tem\n";
                } else {
                    cout << "Indisponivel\n";
                }
            } else {
                cout << "Indisponivel\n";
            }
        }
    }

    return 0;
}