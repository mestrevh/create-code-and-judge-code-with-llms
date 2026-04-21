/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); 

    unordered_set<string> books;
    for (int i = 0; i < n; ++i) {
        if (getline(cin, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            books.insert(line);
        }
    }

    string target;
    if (getline(cin, target)) {
        if (!target.empty() && target.back() == '\r') {
            target.pop_back();
        }
        if (books.find(target) != books.end()) {
            cout << "Sim" << endl;
        } else {
            cout << "Não" << endl;
        }
    }

    return 0;
}