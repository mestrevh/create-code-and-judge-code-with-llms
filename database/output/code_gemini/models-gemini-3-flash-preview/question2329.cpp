/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Friend {
    string name;
    int grams;
};

void processRecursively(int idx, int n, const vector<Friend>& friends, vector<string>& results) {
    if (idx == n) return;
    
    processRecursively(idx + 1, n, friends, results);
    
    int g = friends[idx].grams;
    string name = friends[idx].name;
    
    if (g <= 0) return;
    
    while (g > 400) {
        results.push_back(name + " foi servido(a).");
        results.push_back("Fica tranquilo(a), " + name + " pode se servir novamente!");
        g -= 400;
    }
    results.push_back(name + " foi servido(a).");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Friend> friends(n);
    for (int i = 0; i < n; ++i) {
        cin >> friends[i].name >> friends[i].grams;
    }

    vector<string> results;
    processRecursively(0, n, friends, results);

    for (const string& line : results) {
        cout << line << "\n";
    }

    return 0;
}