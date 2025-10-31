/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> escapes(N);

    for (int i = 0; i < N; i++) {
        cin >> escapes[i].first >> escapes[i].second;
    }

    int remaining = N - 1;
    pair<int, int> chosenEscape = {INT_MAX, INT_MAX};

    for (const auto& escape : escapes) {
        if (escape.first + escape.second < remaining) {
            if (escape.second < chosenEscape.second || 
                (escape.second == chosenEscape.second && escape.first < chosenEscape.first)) {
                chosenEscape = escape;
            }
        }
    }

    if (chosenEscape.first == INT_MAX) {
        chosenEscape = escapes[0];
        for (const auto& escape : escapes) {
            if (escape.second < chosenEscape.second ||
                (escape.second == chosenEscape.second && escape.first < chosenEscape.first)) {
                chosenEscape = escape;
            }
        }
    }

    cout << chosenEscape.first << " " << chosenEscape.second << endl;
    return 0;
}
