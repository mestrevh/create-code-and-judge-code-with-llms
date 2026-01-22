/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Update {
    int friend_id;
    double score;
    string message;
};

bool compare(const Update &a, const Update &b) {
    return a.score > b.score;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<double> proximity(m + 1);
    for (int i = 1; i <= m; i++) {
        int id;
        double degree;
        cin >> id >> degree;
        proximity[id] = degree;
    }

    int x;
    cin >> x;

    vector<Update> updates;
    for (int i = 0; i < x; i++) {
        int friend_id;
        double time;
        string message;

        cin >> friend_id >> time;
        cin.ignore();
        getline(cin, message);

        double score = 0.8 * proximity[friend_id] + 0.2 * time;
        updates.push_back({friend_id, score, message});
    }

    sort(updates.begin(), updates.end(), compare);

    for (int i = 0; i < n && i < updates.size(); i++) {
        cout << updates[i].friend_id << " " << updates[i].message << endl;
    }

    return 0;
}
