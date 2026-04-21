/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormDomino(vector<pair<int, int>>& pieces) {
    vector<int> count(7, 0);
    for (auto& piece : pieces) {
        count[piece.first]++;
        count[piece.second]++;
    }
    int oddCount = 0;
    for (int i = 0; i < 7; i++) {
        if (count[i] % 2 != 0) oddCount++;
    }
    return oddCount <= 1;
}

int main() {
    int N, testCase = 1;
    while (cin >> N && N != 0) {
        vector<pair<int, int>> pieces(N);
        for (int i = 0; i < N; i++) {
            cin >> pieces[i].first >> pieces[i].second;
        }
        cout << "Teste " << testCase++ << endl;
        cout << (canFormDomino(pieces) ? "sim" : "nao") << endl << endl;
    }
    return 0;
}