/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string hero, flower;
    long long H, L;
    if (!getline(cin, hero)) return 0;
    if (!getline(cin, flower)) return 0;
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) { L = stoll(line); break; }
    }
    
    map<string, long long> damage;
    damage["FireFlower"] = 30;
    damage["IceFlower"] = 25;
    damage["BoomerangFlower"] = 35;
    
    long long perHit = damage[flower];
    long long totalDamage = perHit * 4;
    
    if (totalDamage >= L) {
        cout << hero << " conseguiu derrotar o Bowser e salvar a princesa Peach." << "\n";
    } else {
        cout << "O Bowser conseguiu escapar." << "\n";
    }
    return 0;
}