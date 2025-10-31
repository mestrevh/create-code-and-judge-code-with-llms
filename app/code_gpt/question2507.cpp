/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int skill;
};

bool compareThrower(const Player &a, const Player &b) {
    return a.skill < b.skill;
}

bool compareReceiver(const Player &a, const Player &b) {
    return a.skill > b.skill;
}

int main() {
    int N;
    cin >> N;
    vector<Player> throwers(N), receivers(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> throwers[i].name >> throwers[i].skill;
    }
    for (int i = 0; i < N; ++i) {
        cin >> receivers[i].name >> receivers[i].skill;
    }
    
    sort(throwers.begin(), throwers.end(), compareThrower);
    sort(receivers.begin(), receivers.end(), compareReceiver);
    
    for (int i = 0; i < N; ++i) {
        cout << throwers[i].name << " para " << receivers[i].name << endl;
    }
    cout << "I am anything but a dropper" << endl;
    
    return 0;
}
