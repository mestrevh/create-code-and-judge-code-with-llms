/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> even_names;
    vector<string> odd_names;

    for (int i = 0; i < n; ++i) {
        string name;
        int g;
        if (!(cin >> name >> g)) break;
        if (g % 2 == 0) {
            even_names.push_back(name);
        } else {
            odd_names.push_back(name);
        }
    }

    for (const string& name : even_names) {
        cout << name << "\n";
    }
    for (const string& name : odd_names) {
        cout << name << "\n";
    }

    return 0;
}