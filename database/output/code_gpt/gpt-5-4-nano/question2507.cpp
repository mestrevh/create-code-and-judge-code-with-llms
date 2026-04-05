/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    if (!(cin >> X)) return 0;

    vector<pair<string,int>> throwers(X), receivers(X);
    for (int i = 0; i < X; i++) {
        cin >> throwers[i].first >> throwers[i].second;
    }
    for (int i = 0; i < X; i++) {
        cin >> receivers[i].first >> receivers[i].second;
    }

    sort(throwers.begin(), throwers.end(), [](const auto& a, const auto& b){
        return a.second < b.second;
    });
    sort(receivers.begin(), receivers.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });

    for (int i = 0; i < X; i++) {
        cout << throwers[i].first << " para " << receivers[(i+1)%X].first << "\n";
    }
    cout << "I am anything but a dropper\n";
    return 0;
}