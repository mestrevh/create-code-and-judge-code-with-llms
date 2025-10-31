/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
        string line;
        getline(cin, line);
        set<string> items;
        stringstream ss(line);
        string item;
        while (ss >> item) {
            items.insert(item);
        }
        vector<string> unique_items(items.begin(), items.end());
        sort(unique_items.begin(), unique_items.end());
        for (size_t i = 0; i < unique_items.size(); ++i) {
            cout << unique_items[i];
            if (i < unique_items.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
