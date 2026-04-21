/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    vector<pair<int, string>> throwers(X);
    for (int i = 0; i < X; ++i) {
        string name;
        int skill;
        cin >> name >> skill;
        throwers[i] = {skill, name};
    }

    vector<pair<int, string>> receivers(X);
    for (int i = 0; i < X; ++i) {
        string name;
        int skill;
        cin >> name >> skill;
        receivers[i] = {skill, name};
    }

    sort(throwers.begin(), throwers.end());
    sort(receivers.begin(), receivers.end(), greater<pair<int, string>>());

    map<string, string> pass_map;
    for (int i = 0; i < X; ++i) {
        pass_map[throwers[i].second] = receivers[i].second;
    }

    if (X > 0) {
        string start_person = throwers[X - 1].second;
        string current = start_person;
        for (int i = 0; i < X; ++i) {
            string target = pass_map[current];
            cout << current << " para " << target << "\n";
            current = target;
        }
    }

    cout << "I am anything but a dropper" << endl;

    return 0;
}