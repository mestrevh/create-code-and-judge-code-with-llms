/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;
    unordered_map<char, int> holes = {
        {'A', 1}, {'B', 2}, {'C', 0}, {'D', 1}, {'E', 0},
        {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0},
        {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 1},
        {'P', 1}, {'Q', 1}, {'R', 1}, {'S', 0}, {'T', 0},
        {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0}, {'Y', 0},
        {'Z', 0}
    };
    
    cin.ignore();
    while (T--) {
        string text;
        getline(cin, text);
        int totalHoles = 0;
        for (char c : text) {
            totalHoles += holes[c];
        }
        cout << totalHoles << endl;
    }
    return 0;
}
