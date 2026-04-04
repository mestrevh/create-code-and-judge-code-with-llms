/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); 

    while (n--) {
        if (!getline(cin, line)) break;
        
        stringstream ss(line);
        string item;
        set<string> lista_compras;
        
        while (ss >> item) {
            lista_compras.insert(item);
        }

        bool first = true;
        for (const string& s : lista_compras) {
            if (!first) {
                cout << " ";
            }
            cout << s;
            first = false;
        }
        cout << "\n";
    }

    return 0;
}