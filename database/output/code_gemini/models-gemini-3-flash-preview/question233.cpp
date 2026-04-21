/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    unordered_map<string, int> dictionary;
    dictionary.reserve(m);

    for (int i = 0; i < m; ++i) {
        string word;
        int value;
        cin >> word >> value;
        dictionary[word] = value;
    }

    for (int i = 0; i < n; ++i) {
        long long total_salary = 0;
        string word;
        while (cin >> word && word != ".") {
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                total_salary += it->second;
            }
        }
        cout << total_salary << "\n";
    }

    return 0;
}