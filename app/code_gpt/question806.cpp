/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> lines(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, lines[i]);
    }
    
    string query;
    getline(cin, query);

    map<char, int> countMap;

   ```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> lines(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, lines[i]);
    }
    
    string query;
    getline(cin, query);

    map<char, int> countMap;

    for (const auto& line : lines) {
        for (char c : line) {
            countMap[c]++;
        }
    }

    for (char c : query) {
        cout << c << " = " << countMap[c] << endl;
    }

    return 0;
}
