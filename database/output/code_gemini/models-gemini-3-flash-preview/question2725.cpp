/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Candidate {
    int number;
    string name;
    string party;
    int votes;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Candidate> candidates(5);
    for (int i = 0; i < 5; ++i) {
        if (!(cin >> candidates[i].number)) break;
        if (!(cin >> candidates[i].name)) break;
        if (!(cin >> candidates[i].party)) break;
        candidates[i].votes = 0;
    }

    int vote;
    while (cin >> vote && vote != 0) {
        for (int i = 0; i < 5; ++i) {
            if (candidates[i].number == vote) {
                candidates[i].votes++;
                break;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << candidates[i].party << " " 
             << candidates[i].number << " " 
             << candidates[i].name << ": " 
             << candidates[i].votes << "\n";
    }

    return 0;
}